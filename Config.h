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

Config* config_new(const char* file);

void config_subs_add(Config* conf, Channel* channel);

void config_free(Config* conf);

#endif //YOUTUBE_CONFIG_H
