//
// Created by Rhys on 18/02/2022.
//

#include <Channel.h>

#include <Config.h>

mm::Channel::Channel(std::string id) {
    ptr = channel_new(id.c_str());
}

mm::Channel::Channel() {
    ptr = NULL;
}

struct ::Channel* mm::Channel::cptr() {
    return ptr;
}

mm::Channel* mm::Channel::from_name(std::string name, mm::Config* conf) {
    mm::Channel* out = new mm::Channel;
    out->ptr = channel_new_from_name(name.c_str(), conf->cptr());

    return out;
}

std::string mm::Channel::id() {
    return std::string(ptr->id);
}

std::string mm::Channel::name(mm::Config* conf) {
    return std::string(channel_name(ptr, conf->cptr()));
}

void mm::Channel::get_vids(vid_cb callback, mm::Config* conf, void *data) {
    channel_get_vids(ptr, conf->cptr(), callback, data);
}

mm::Channel::~Channel() {
    channel_free(ptr);
}