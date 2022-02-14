//
// Created by rhys on 13/02/2022.
//

#include "Config.h"
#include "Util.h"

#include <cJSON.h>

#include <stdlib.h>
#include <stdio.h>

const char* read_file(const char* fname){
    char * buffer = 0;
    long length;
    FILE* file = fopen (fname, "rb");

    if (file) {
        fseek (file, 0, SEEK_END);
        length = ftell (file);
        fseek (file, 0, SEEK_SET);
        buffer = malloc (length);

        if (buffer) {
            fread (buffer, 1, length, file);
        }

        fclose (file);
    }

    return buffer;
}

void config_load(Config* conf){
    const char* data = read_file(conf->file);

    cJSON* json = cJSON_Parse(data);

    conf->quality = cJSON_GetObjectItem(json, "quality")->valueint;

    cJSON* subs = cJSON_GetObjectItem(json, "subs");

    cJSON* sub;
    cJSON_ArrayForEach(sub, subs){
        if(cJSON_IsString(sub)) {
            Channel* c = channel_new(sub->valuestring);

            config_subs_add(conf, c);
        }
    }

    cJSON_Delete(json);
}

void config_save(Config* conf){
    const char* data = read_file(conf->file);

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

Config* config_new(const char* file) {
    Config* out = malloc(sizeof(Config));

    out->file = strdup(file);
    out->quality = 480;
    out->subs = malloc(sizeof(Subs));

    out->subs->array = malloc(1);
    out->subs->length = 0;

    config_load(out);

    return out;
}

void config_free(Config *conf) {
    free((void*) conf->file);
    if(conf->subs->length > 0) {
        for(int i=0 ; i<conf->subs->length ; i++){
            channel_free(conf->subs->array[i]);
        }
        free(conf->subs->array);
    }
    free(conf->subs);
}

void config_subs_add(Config* conf, Channel* channel) {
    conf->subs->length++;

    conf->subs->array = realloc(conf->subs->array, conf->subs->length*sizeof(Channel*));

    conf->subs->array[conf->subs->length-1] = channel;
}

int config_get_vids(Config *conf, vid_cb callback, void *data) {
    for(int i=0 ; i<conf->subs->length ; i++){
        //TODO Threading
        Channel* c = conf->subs->array[i];
        channel_get_vids(c, callback, data);
    }
}

void config_vid_list_appender(Video* vid, void* ptr){
    Videos* vids = ptr;

    vids->length++;
    vids->array = realloc(vids->array, vids->length*sizeof(Video*));

    vids->array[vids->length-1] = vid;
}

Videos* config_get_vids_list(Config *conf) {
    Videos* vids = malloc(sizeof(Videos));
    vids->length = 0;
    vids->array = malloc(1);

    config_get_vids(conf, config_vid_list_appender, (void*) vids);

    return vids;
}

void videos_free(Videos* vids) {
    for(int i=0 ; i<vids->length ; i++){
        video_free(vids->array[i]);
    }

    free(vids);
}
