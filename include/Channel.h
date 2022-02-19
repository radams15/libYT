//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CHANNEL_H
#define YOUTUBE_CHANNEL_H

#include "Video.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*vid_cb)(struct Video*, void*);

struct Channel{
    char* id;
    char* name;
};

struct Channel* channel_new(const char* id);

struct Channel* channel_new_from_name(const char* name, struct Config* conf);

const char* channel_name(struct Channel* channel, struct Config* conf);

int channel_get_vids(struct Channel* channel, struct Config* conf, vid_cb callback, void* data);

void channel_free(struct Channel* channel);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace mm{
    class Config;

    class Channel{
    private:
        struct ::Channel* ptr;

    public:
        Channel();
        explicit Channel(std::string id);

        static Channel* from_name(std::string name, mm::Config* conf);

        std::string id();
        std::string name(Config* conf);
        void get_vids(vid_cb callback, mm::Config* conf, void* data=NULL);

        struct ::Channel* cptr();

        ~Channel();
    };
}
#endif

#endif //YOUTUBE_CHANNEL_H
