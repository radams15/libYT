//
// Created by rhys on 13/02/2022.
//

#include "Config.h"
#include "Util.h"

#include <cJSON.h>

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void config_load(struct Config* conf){
    const char* data = read_file(conf->file);
    if(data == NULL){
        return;
    }
	
    cJSON* json = cJSON_Parse(data);

    conf->quality = cJSON_GetObjectItem(json, "quality")->valueint;

    cJSON* subs = cJSON_GetObjectItem(json, "subs");

    cJSON* sub;
    cJSON_ArrayForEach(sub, subs){
        if(cJSON_IsString(sub)) {
            struct Channel* c = channel_new(sub->valuestring);

            config_subs_add(conf, c);
        }
    }

    cJSON_Delete(json);
}

void config_save(struct Config* conf){
    cJSON* json = cJSON_CreateObject();

    cJSON_AddNumberToObject(json, "quality", conf->quality);

    cJSON* subs = cJSON_AddArrayToObject(json, "subs");
    for(int i=0 ; i<conf->subs->length ; i++) {
        cJSON_AddItemToArray(subs, cJSON_CreateString(conf->subs->array[i]->id));
    }

    FILE *out;
    if ((out = fopen(conf->file, "w")) != NULL) {
        fprintf(out, "%s\n", cJSON_Print(json));
        fclose(out);
    }


    cJSON_Delete(json);
}

struct Config* config_new(const char* file, int use_proxy) {
    struct Config* out = malloc(sizeof(struct Config));

    out->file = strdup(file);
    out->invidious_inst = strdup("http://vid.puffyan.us"); //TODO load from file.
    out->quality = 480;
    out->subs = malloc(sizeof(struct Subs));
    out->use_threading = 1;

    out->subs->array = malloc(1);
    out->subs->length = 0;

    out->use_proxy = use_proxy;
    out->proxy_url = strdup("http://therhys.co.uk/yt/proxy.php?url=");

    config_load(out);

    return out;
}

void config_free(struct Config *conf) {
    free((void*) conf->file);
    if(conf->subs->length > 0) {
        for(int i=0 ; i<conf->subs->length ; i++){
            channel_free(conf->subs->array[i]);
        }
        free(conf->subs->array);
    }
    free(conf->subs);
}

void config_subs_add(struct Config* conf, struct Channel* channel) {
    conf->subs->length++;

    conf->subs->array = realloc(conf->subs->array, conf->subs->length*sizeof(struct Channel*));

    conf->subs->array[conf->subs->length-1] = channel;
}


struct ThreadData{
    struct Channel* c;
    struct Config* conf;
    vid_cb callback;
    void *data;
};

void* get_vid(void* ptr){
    struct ThreadData* data = ptr;

    channel_get_vids(data->c, data->conf, data->callback, data->data);

    pthread_exit(NULL);
}

int config_get_vids(struct Config *conf, vid_cb callback, void *data) {
    if(conf->use_threading) {
        pthread_t *threads = malloc(conf->subs->length * sizeof(pthread_t));

        for (int i = 0; i < conf->subs->length; i++) {
            struct Channel *c = conf->subs->array[i];

            struct ThreadData *thread_data = malloc(sizeof(struct ThreadData));

            thread_data->c = c;
            thread_data->conf = conf;
            thread_data->callback = callback;
            thread_data->data = data;

            pthread_create(&threads[i], NULL, get_vid, thread_data);
        }

        for (int i = 0; i < conf->subs->length; i++) {
            void *status;
            pthread_join(threads[i], &status);
        }
    }else{
        for (int i = 0; i < conf->subs->length; i++) {
            struct Channel *c = conf->subs->array[i];

            channel_get_vids(c, conf, callback, data);
        }
    }

    return EXIT_SUCCESS;
}

void config_vid_list_appender(struct Video* vid, void* ptr){
    struct Videos* vids = ptr;

    vids->length++;
    vids->array = realloc(vids->array, vids->length*sizeof(struct Video*));

    vids->array[vids->length-1] = vid;
}

struct Videos* config_get_vids_list(struct Config *conf) {
    struct Videos* vids = malloc(sizeof(struct Videos));
    vids->length = 0;
    vids->array = malloc(1);

    config_get_vids(conf, config_vid_list_appender, (void*) vids);

    return vids;
}

struct Video* videos_get(struct Videos* vids, int index){
    if(index >=0 && index < vids->length){
        return vids->array[index];
    }

    return NULL;
}

void videos_free(struct Videos* vids) {
    for(int i=0 ; i<vids->length ; i++){
        video_free(vids->array[i]);
    }

    free(vids);
}