//
// Created by Rhys on 18/02/2022.
//

#include <Video.h>

#include <Config.h>

mm::Video::Video(struct ::Video *ptr) {
    this->ptr = ptr;
}

struct ::Video* mm::Video::cptr() {
    return ptr;
}


std::string mm::Video::id() {
    return std::string(ptr->id);
}

std::string mm::Video::title() {
    return std::string(ptr->title);
}

std::string mm::Video::channel_name() {
    return std::string(ptr->channel_name);
}

std::string mm::Video::channel_id() {
    return std::string(ptr->channel_id);
}

size_t mm::Video::published() {
    return ptr->published;
}

std::string mm::Video::get_playable(mm::Config *conf) {
    return std::string(video_get_playable(ptr, conf->cptr()));
}

mm::Video::~Video() {
    video_free(ptr);
}