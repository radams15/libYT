//
// Created by Rhys on 18/02/2022.
//

#include <Channel.h>

#include <Config.h>

mm::Channel::Channel(std::string id, mm::Config* conf) {
    ptr = channel_new(id.c_str());

    this->conf = conf;
}

std::string mm::Channel::id() {
    return std::string(ptr->id);
}

std::string mm::Channel::name() {
    return std::string(channel_name(ptr, conf->cptr()));
}

void mm::Channel::get_vids(vid_cb callback, void *data) {
    channel_get_vids(ptr, conf->cptr(), callback, data);
}

mm::Channel::~Channel() {
    channel_free(ptr);
}