//
// Created by rhys on 13/02/2022.
//

#include "Video.h"
#include "Net.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Config.h"
#include "cJSON.h"

#define FREE_NOTNULL(a) if(strlen(a) > 0){ free((void*) a); }

void video_free(struct Video *video) {
    FREE_NOTNULL(video->id)
    FREE_NOTNULL(video->title)
    FREE_NOTNULL(video->channel_name)
    FREE_NOTNULL(video->channel_id)

    free(video);
}

struct Video* video_new() {
    struct Video* out = malloc(sizeof(struct Video));

    out->id = "";
    out->title = "";
    out->channel_name = "";
    out->channel_id = "";

    return out;
}

const char* video_get_playable(struct Video* video, struct Config* conf) {
    unsigned int len = strlen(conf->invidious_inst) + strlen(video->id) + 32;

    char* url = malloc((len*sizeof(char))+5);

    sprintf(url, "%s/api/v1/videos/%s", conf->invidious_inst, video->id);

    const char* raw = net_get(url, conf->use_proxy, conf->proxy_url);

    free(url);

    printf("Raw: %s\n", raw);

    cJSON* json = cJSON_Parse(raw);

    cJSON* streams = cJSON_GetObjectItem(json, "formatStreams");

    cJSON* stream;

    printf("Get quality: %d\n", conf->quality);

    cJSON_ArrayForEach(stream, streams){
        char* quality_str = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(stream, "resolution")));
        quality_str[strlen(quality_str)-1] = 0;
        if(quality_str[strlen(quality_str)-1] == 'p') {
            quality_str[strlen(quality_str) - 1] = 0;
        }

        printf("Quality: %s\n", quality_str);

        int quality = atoi(quality_str);

        if(quality == conf->quality){
            return strdup(cJSON_GetStringValue(cJSON_GetObjectItem(stream, "url")));
        }
    }

    // not found exact match - get closest but smaller.
    cJSON_ArrayForEach(stream, streams){
        char* quality_str = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(stream, "resolution")));
        if(quality_str[strlen(quality_str)-1] == 'p') {
            quality_str[strlen(quality_str) - 1] = 0;
        }
        printf("Quality: %s\n", quality_str);

        int quality = atoi(quality_str);

        free(quality_str);

        if(quality >= conf->quality){
            return strdup(cJSON_GetStringValue(cJSON_GetObjectItem(stream, "url")));
        }
    }

    return "No streams found!";
}
