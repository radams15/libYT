//
// Created by rhys on 13/02/2022.
//

#include "Channel.h"
#include "Net.h"
#include "Config.h"
#include "cJSON.h"
#include "Util.h"
#include "Sort.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex;

struct Channel* channel_new(const char* id) {
    struct Channel* out = malloc(sizeof(struct Channel));

    out->id = strdup(id);
    out->name = "";
    out->sub_count = 0;
    out->video_count = 0;

    return out;
}

struct Channel* channel_new_from_name(const char *name, struct Config* conf) {
    char* url = calloc(strlen(conf->invidious_inst) + strlen(name) + 64, sizeof(char));

    sprintf(url, "%s/api/v1/search?type=channel&q=%s", conf->invidious_inst, name);

    const char* raw = net_get(url, conf->use_proxy, conf->proxy_url);
    free(url);

    cJSON* json = cJSON_Parse(raw);

    if(json == NULL){
        fprintf(stderr, "Internal libyt error - NULL returned from invidious: %s\n", raw);
        return NULL;
    }

    free(raw);

    if(cJSON_GetArraySize(json) == 0){
        fprintf(stderr, "Cannot find valid channel name for: %s\n", name);

        cJSON_free(json);

        return NULL;
    }

    cJSON* first_result = cJSON_GetArrayItem(json, 0);

    const char* id = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(first_result, "authorID")));

    cJSON_free(json);

    return channel_new(id);
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

        const char* raw = net_get(url, conf->use_proxy, conf->proxy_url);

        free(url);

        cJSON* json = cJSON_Parse(raw);

        if(json == NULL){
            fprintf(stderr, "Internal libyt error - NULL returned from invidious: %s\n", raw);
            return "(NULL)";
        }

        free(raw);

        channel->name = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(json, "author")));

        cJSON_free(json);
    }

    return (const char*) channel->name;
}

const char* vid_get_thumbnail(void* thumbnails){
    cJSON* thumb;
    cJSON* thumbs = thumbnails;

    cJSON_ArrayForEach(thumb, thumbs){
        int width = cJSON_GetNumberValue(cJSON_GetObjectItem(thumb, "width"));
        char* url = cJSON_GetStringValue(cJSON_GetObjectItem(thumb, "url"));

        if(width <= 240 && strcmp(url, "") != 0){
            return strdup(url);
        }

        free(url);
    }
}

int channel_get_vids(struct Channel *channel, struct Config* conf, vid_cb callback, void* data) {
    char* url = calloc(strlen(conf->invidious_inst) + strlen(channel->id) + 32, sizeof(char));

    sprintf(url, "%s/api/v1/channels/%s", conf->invidious_inst, channel->id);

    const char* raw = net_get(url, conf->use_proxy, conf->proxy_url);
	
    free(url);

    cJSON* json = cJSON_Parse(raw);

    if(json == NULL){
        fprintf(stderr, "Internal libyt error - NULL returned from invidious: %s\n", raw);
        return "(NULL)";
    }

    free(raw);

    cJSON* videos = cJSON_GetObjectItem(json, "latestVideos");

    cJSON* video;
    cJSON_ArrayForEach(video, videos){
        struct Video* v = video_new();

        v->channel_name = strdup(channel_name(channel, conf));
        v->channel_id = strdup(channel->id);

        v->title = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(video, "title")));
        v->id = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(video, "videoID")));
        v->published = cJSON_GetNumberValue(cJSON_GetObjectItem(video, "published"));
        v->thumbnail = vid_get_thumbnail(cJSON_GetObjectItem(video, "videoThumbnails"));

        pthread_mutex_lock(&mutex);
        callback(v, data);
        pthread_mutex_unlock(&mutex);
    }

    cJSON_free(json);
    cJSON_free(videos);

    return 0;
}

List_t *channel_get_vids_list(Channel_t *channel, Config_t *conf) {
    List_t* vids = malloc(sizeof(struct List));
    vids->length = 0;
    vids->arry = malloc(1);

    channel_get_vids(channel, conf, config_video_list_appender, (void *) vids);

    sort_vids(vids->arry, vids->length, 0, vids->length - 1);
    reverse_vids(vids->arry, vids->length);

    return vids;
}

void channel_search(Config_t *conf, const char *query, int page, channel_cb callback, void *data) {
    char* url = calloc(strlen(conf->invidious_inst) + strlen(query) + 32, sizeof(char));

    sprintf(url, "%s/api/v1/search?q=%s&type=channel&page=%d", conf->invidious_inst, query, page);

    const char* raw = net_get(url, conf->use_proxy, conf->proxy_url);

    free(url);

    cJSON* json = cJSON_Parse(raw);

    if(json == NULL){
        fprintf(stderr, "Internal libyt error - NULL returned from invidious: %s\n", raw);
        return;
    }

    free(raw);

    cJSON* channel;
    cJSON_ArrayForEach(channel, json){
        struct Channel* c = channel_new(cJSON_GetStringValue(cJSON_GetObjectItem(channel, "authorId")));

        c->name = strdup(cJSON_GetStringValue(cJSON_GetObjectItem(channel, "author")));
        c->sub_count = (long) cJSON_GetNumberValue(cJSON_GetObjectItem(channel, "subCount"));
        c->video_count = (long) cJSON_GetNumberValue(cJSON_GetObjectItem(channel, "videoCount"));

        callback(c, data);
    }

    cJSON_free(json);
}

List_t* channel_search_list(Config_t *conf, const char *query, int page) {
    List_t* channels = malloc(sizeof(struct List));
    channels->length = 0;
    channels->arry = malloc(1);

    channel_search(conf, query, page, config_channel_list_appender, (void *) channels);

    return channels;
}
