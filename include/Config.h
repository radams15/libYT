//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CONFIG_H
#define YOUTUBE_CONFIG_H

#include <Net.h>
#include <Video.h>
#include <Videos.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*vid_cb)(Video_t*, void*);

typedef struct Config{
    const char* fname;
    int quality;
    struct Subs* subs;
    const char* invidious_inst;
    int use_threading;
    int use_proxy;
    const char* proxy_url;
} Config_t;

#include <Channel.h>

typedef struct Subs{
    Channel_t** arry;
    int length;
} Subs_t;

Config_t* config_new(const char* fname, int use_proxy);

void config_subs_add(Config_t* conf, Channel_t* channel);

void config_save(Config_t* conf);

Videos_t* config_get_vids_list(Config_t* conf);

int config_get_vids(Config_t* conf, vid_cb callback, void* data);

const char* video_get_playable(Video_t* video, Config_t* conf);

void config_free(Config_t* conf);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_CONFIG_H
