//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CONFIG_H
#define YOUTUBE_CONFIG_H

#include "Channel.h"

typedef struct {
    Channel** array;
    int length;
} Subs;

typedef struct {
    const char* file;
    int quality;
    Subs* subs;
} Config;

typedef struct {
    Video** array;
    int length;
} Videos;

Config* config_new(const char* file);

void config_subs_add(Config* conf, Channel* channel);

Videos* config_get_vids_list(Config* conf);
void videos_free(Videos* vids);

Video* videos_get(Videos* vids, int index);

int config_get_vids(Config* conf, vid_cb callback, void* data);

void config_free(Config* conf);

#endif //YOUTUBE_CONFIG_H
