//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_CONFIG_H
#define YOUTUBE_CONFIG_H

#include <Channel.h>
#include <Net.h>

#ifdef __cplusplus
extern "C"{
#endif

struct Subs{
    struct Channel** array;
    int length;
};

struct Config{
    const char* file;
    int quality;
    struct Subs* subs;
    const char* invidious_inst;
    int use_threading;
    struct Net* net;
};

struct Videos {
    struct Video** array;
    int length;
};

struct Config* config_new(const char* file, int use_proxy);

void config_subs_add(struct Config* conf, struct Channel* channel);

struct Videos* config_get_vids_list(struct Config* conf);
void videos_free(struct Videos* vids);

struct Video* videos_get(struct Videos* vids, int index);

int config_get_vids(struct Config* conf, vid_cb callback, void* data);

void config_free(struct Config* conf);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>
#include <vector>

namespace mm{
    class Video;

    class Config{

    private:
        struct ::Config* ptr;

    public:
        Config(const std::string& file, bool use_proxy=false);

        void get_vids(vid_cb callback, void* data=NULL);

        std::vector<Video*>* get_vids_list();

        struct ::Config* cptr();

        Net* net();

        ~Config();
    };
}
#endif

#endif //YOUTUBE_CONFIG_H
