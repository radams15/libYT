//
// Created by rhys on 13/02/2022.
//

#include "Config.h"
#include "Util.h"
#include "List.h"
#include "Sort.h"

#include <cJSON.h>

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void config_load(struct Config* conf){
    const char* data = read_file(conf->fname);
    if(data == NULL){
        return;
    }
	
    cJSON* json = cJSON_Parse(data);
    free((void*) data);

    conf->quality = cJSON_GetObjectItem(json, "quality")->valueint;

    const char* inst = cJSON_GetStringValue(cJSON_GetObjectItem(json, "instance"));
    if(inst != NULL){
        free((void*)conf->invidious_inst);
        conf->invidious_inst = strdup(inst);
    }

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
    cJSON_AddStringToObject(json, "instance", conf->invidious_inst);

    cJSON* subs = cJSON_AddArrayToObject(json, "subs");
    for(int i=0 ; i<conf->subs->length ; i++) {
        if(conf->subs->arry[i] == NULL){
            continue;
        }
        cJSON_AddItemToArray(subs, cJSON_CreateString(((Channel_t*)conf->subs->arry[i])->id));
    }

    FILE *out;
    if ((out = fopen(conf->fname, "w")) != NULL) {
        fprintf(out, "%s\n", cJSON_Print(json));
        fclose(out);
    }


    cJSON_Delete(json);
}

struct Config* config_new(const char* fname, int use_proxy) {
    struct Config* out = malloc(sizeof(struct Config));

    out->fname = strdup(fname);
    out->invidious_inst = strdup("http://vid.puffyan.us");
    out->quality = 480;
    out->subs = malloc(sizeof(List_t));
    out->use_threading = 1;

    out->subs->arry = malloc(1);
    out->subs->length = 0;

    out->use_proxy = use_proxy;
    out->proxy_url = "";

    config_load(out);

    return out;
}

void config_free(struct Config *conf) {
    free((void*) conf->fname);
    if(conf->subs->length > 0) {
        for(int i=0 ; i<conf->subs->length ; i++){
            if(conf->subs->arry[i] == NULL){
                continue;
            }
            channel_free(conf->subs->arry[i]);
        }
        free(conf->subs->arry);
    }
    free(conf->subs);
    free(conf);
}

void config_subs_add(struct Config* conf, struct Channel* channel) {
    conf->subs->length++;

    conf->subs->arry = realloc(conf->subs->arry, conf->subs->length * sizeof(struct Channel*));

    conf->subs->arry[conf->subs->length - 1] = channel;
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
        struct ThreadData** thread_datas = malloc(conf->subs->length * sizeof(struct ThreadData *));

        for (int i = 0; i < conf->subs->length; i++) {
            struct Channel *c = conf->subs->arry[i];
            if(c == NULL){
                continue;
            }

            struct ThreadData *thread_data = malloc(sizeof(struct ThreadData));

            thread_data->c = c;
            thread_data->conf = conf;
            thread_data->callback = callback;
            thread_data->data = data;

            thread_datas[i] = thread_data;

            pthread_create(&threads[i], NULL, get_vid, thread_data);
        }

        for (int i = 0; i < conf->subs->length; i++) {
            if(conf->subs->arry[i] == NULL){
                continue;
            }

            void *status;
            pthread_join(threads[i], &status);
            free((void*)thread_datas[i]);
        }
        free((void*) thread_datas);
        free((void*) threads);
    }else{
        for (int i = 0; i < conf->subs->length; i++) {
            struct Channel *c = conf->subs->arry[i];

            channel_get_vids(c, conf, callback, data);
        }
    }

    return EXIT_SUCCESS;
}



struct List* config_get_vids_list(struct Config *conf) {
    struct List* vids = malloc(sizeof(struct List));
    vids->length = 0;
    vids->arry = malloc(1);

    config_get_vids(conf, config_video_list_appender, (void *) vids);

    sort_vids((Video_t**) vids->arry, vids->length, 0, vids->length - 1);
    reverse_vids(vids->arry, vids->length);

    return vids;
}

void config_video_search(Config_t *conf, const char *query, int page, vid_cb callback, void *data) {
    char* url = calloc(strlen(conf->invidious_inst) + strlen(query) + 32, sizeof(char));

    sprintf(url, "%s/api/v1/search?q=%s&type=video&page=%d", conf->invidious_inst, query, page);

    const char* raw = net_get(url, conf->use_proxy, conf->proxy_url);

    free(url);

    cJSON* json = cJSON_Parse(raw);
    free(raw);

    cJSON* video;
    cJSON_ArrayForEach(video, json){
        struct Video* v = video_new();

        v->channel_name = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(video, "author")));
        v->channel_id = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(video, "authorId")));

        v->title = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(video, "title")));
        v->id = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(video, "videoID")));
        v->published = cJSON_GetNumberValue(cJSON_GetObjectItem(video, "published"));

        callback(v, data);
    }

    cJSON_free(json);
}

List_t *config_video_search_list(Config_t *conf, const char *query, int page) {
    struct List* vids = malloc(sizeof(struct List));
    vids->length = 0;
    vids->arry = malloc(1);

    config_video_search(conf, query, page, config_video_list_appender, (void *) vids);

    return vids;
}

void config_subs_rm(Config_t *conf, Channel_t *channel) {
    for(int i=0 ; i<conf->subs->length ; i++){
        Channel_t* c = channels_get(conf->subs, i);

        if(c == NULL){
            continue;
        }

        if(strcmp(c->id, channel->id) == 0){
            channel_free(c);
            conf->subs->arry[i] = NULL;
        }
    }
}

struct Video* videos_get(struct List* vids, int index){
    if(index >=0 && index < vids->length){
        return (Video_t*) vids->arry[index];
    }

    return NULL;
}

struct Channel* channels_get(struct List* channels, int index){
    if(index >=0 && index < channels->length){
        return (Channel_t*) channels->arry[index];
    }

    return NULL;
}

void videos_free(struct List* vids) {
    for(int i=0 ; i<vids->length ; i++){
        video_free(vids->arry[i]);
    }

    free(vids);
}

void channels_free(List_t* channels){
    for(int i=0 ; i<channels->length ; i++){
        channel_free(channels->arry[i]);
    }

    free(channels);
}