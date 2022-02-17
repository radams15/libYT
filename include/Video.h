//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_VIDEO_H
#define YOUTUBE_VIDEO_H

#ifdef __cplusplus
extern "C"{
#endif

struct Config;

struct Video {
    char* link;
    char* title;
    char* channel_name;
    char* channel_id;
    char* publish_date;
} Video;

struct Video* video_new();
void video_free(struct Video* video);

const char* video_get_playable(struct Video* video, struct Config* conf);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_VIDEO_H
