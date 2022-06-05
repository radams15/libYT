//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_VIDEO_H
#define YOUTUBE_VIDEO_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct Video {
    char* id;
    char* title;
    char* channel_name;
    char* channel_id;
    char* thumbnail;
    long published;
} Video_t;

Video_t* video_new();
void video_free(Video_t* video);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_VIDEO_H
