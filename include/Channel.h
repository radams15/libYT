//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CHANNEL_H
#define YOUTUBE_CHANNEL_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct Channel{
    char* id;
    char* name;
} Channel_t;

#include <Config.h>

Channel_t* channel_new(const char* id);

Channel_t* channel_new_from_name(const char* name, Config_t* conf);

const char* channel_name(Channel_t* channel, Config_t* conf);

int channel_get_vids(Channel_t* channel, Config_t* conf, vid_cb callback, void* data);

void channel_free(Channel_t* channel);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_CHANNEL_H
