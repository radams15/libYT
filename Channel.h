//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CHANNEL_H
#define YOUTUBE_CHANNEL_H

#include "Video.h"

typedef void (*channel_cb)(Video*, void*);

typedef struct{
    char* id;
    char* name;
} Channel;

Channel* channel_new(const char* id);

const char* channel_name(Channel* channel);

int channel_get_vids(Channel* channel, channel_cb callback, void* data);

void channel_free(Channel* channel);

#endif //YOUTUBE_CHANNEL_H
