//
// Created by rhys on 13/02/2022.
//

#include "Channel.h"
#include "Util.h"
#include "Net.h"
#include "Config.h"
#include "cJSON.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Channel* channel_new(const char* id) {
    struct Channel* out = malloc(sizeof(struct Channel));

    out->id = strdup(id);
    out->name = "";

    return out;
}

void channel_free(struct Channel* channel) {
    free(channel->id);
    if(strlen(channel->name) > 0){
        free(channel->name);
    }

    free(channel);
}

const char* channel_name(struct Channel* channel, struct Config* conf) {
    if(strlen(channel->name) == 0){
        char* url = calloc(strlen(conf->invidious_inst) + strlen(channel->id) + 32, sizeof(char));

        sprintf(url, "%s/api/v1/channels/%s", conf->invidious_inst, channel->id);

        const char* raw = net_get(url);

        free(url);

        cJSON* json = cJSON_Parse(raw);

        channel->name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "author"));

        cJSON_free(json);
    }

    return (const char*) channel->name;
}

int channel_get_vids(struct Channel *channel, struct Config* conf, vid_cb callback, void* data) {
    char* url = calloc(strlen(conf->invidious_inst) + strlen(channel->id) + 32, sizeof(char));

    sprintf(url, "%s/api/v1/channels/%s", conf->invidious_inst, channel->id);

    const char* raw = net_get(url);
	
    free(url);

    cJSON* json = cJSON_Parse(raw);

    cJSON* videos = cJSON_GetObjectItem(json, "latestVideos");

    cJSON* video;
    cJSON_ArrayForEach(video, videos){
        struct Video* v = video_new();

        v->channel_name = strdup(channel_name(channel, conf));
        v->channel_id = strdup(channel->id);

        v->title = cJSON_GetStringValue(cJSON_GetObjectItem(video, "title"));
        v->id = cJSON_GetStringValue(cJSON_GetObjectItem(video, "videoID"));
        v->published = cJSON_GetNumberValue(cJSON_GetObjectItem(video, "lengthSeconds"));

        callback(v, data);
    }

    cJSON_free(json);
    cJSON_free(videos);

    return 0;
}