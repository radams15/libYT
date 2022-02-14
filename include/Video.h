//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_VIDEO_H
#define YOUTUBE_VIDEO_H

typedef struct {
    char* link;
    char* title;
    char* channel_name;
    char* channel_id;
    char* publish_date;
} Video;

Video* video_new();
void video_free(Video* video);

const char* video_get_playable(Video* video, int quality);

#endif //YOUTUBE_VIDEO_H
