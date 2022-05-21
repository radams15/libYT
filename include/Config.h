//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CONFIG_H
#define YOUTUBE_CONFIG_H

#include <Net.h>
#include <Video.h>
#include <List.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*vid_cb)(Video_t*, void*);

typedef struct Config{
    const char* fname;
    int quality;
    struct List* subs;
    const char* invidious_inst;
    int use_threading;
    int use_proxy;
    const char* proxy_url;
} Config_t;

#include <Channel.h>

Config_t* config_new(const char* fname, int use_proxy);

void config_subs_add(Config_t* conf, Channel_t* channel);

void config_save(Config_t* conf);

List_t* config_get_vids_list(Config_t* conf);

int config_get_vids(Config_t* conf, vid_cb callback, void* data);

const char* video_get_playable(Video_t* video, Config_t* conf);

void config_free(Config_t* conf);

void config_video_search(Config_t* conf, const char* query, int page, vid_cb callback, void* data);
List_t* config_video_search_list(Config_t* conf, const char* query, int page);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_CONFIG_H
