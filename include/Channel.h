//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CHANNEL_H
#define YOUTUBE_CHANNEL_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct Channel {
    char* id;
    char* name;
    long sub_count;
    long video_count;
} Channel_t;

typedef struct Channels {
    Channel_t** arry;
    long length;
} Channels_t;

typedef void (*channel_cb)(Channel_t*, void*);

#include <Config.h>

Channel_t* channel_new(const char* id);

const char* vid_get_thumbnail(void* thumbnails);

Channel_t* channel_new_from_name(const char* name, Config_t* conf);

void channel_search(Config_t* conf, const char* query, int page, channel_cb callback, void* data);
List_t* channel_search_list(Config_t* conf, const char* query, int page);

const char* channel_name(Channel_t* channel, Config_t* conf);

int channel_get_vids(Channel_t* channel, Config_t* conf, vid_cb callback, void* data);
List_t* channel_get_vids_list(Channel_t* channel, Config_t* conf);

void channel_free(Channel_t* channel);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_CHANNEL_H
