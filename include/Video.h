//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_VIDEO_H
#define YOUTUBE_VIDEO_H

#ifdef __cplusplus
extern "C"{
#endif

#define size_t int

struct Config;

struct Video {
    char* id;
    char* title;
    char* channel_name;
    char* channel_id;
    size_t published;
};

struct Video* video_new();
void video_free(struct Video* video);

const char* video_get_playable(struct Video* video, struct Config* conf);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace mm{
    class Config;

    class Video{
    private:
        struct ::Video* ptr;
    public:
        Video(struct ::Video* ptr);

        std::string id();
        std::string title();
        std::string channel_name();
        std::string channel_id();
        size_t published();

        struct ::Video* cptr();

        std::string get_playable(Config* conf);

        ~Video();
    };
}
#endif

#endif //YOUTUBE_VIDEO_H
