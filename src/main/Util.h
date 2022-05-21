//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_UTIL_H
#define YOUTUBE_UTIL_H

#include "Video.h"
#include "Channel.h"

char* strdup(const char* in);
const char* read_file(const char* fname);
void config_video_list_appender(Video_t* vid, void* ptr);
void config_channel_list_appender(Channel_t* vid, void* ptr);

#endif //YOUTUBE_UTIL_H
