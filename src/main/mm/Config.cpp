//
// Created by Rhys on 18/02/2022.
//

#include <Config.h>
#include <Net.h>

mm::Config::Config(const std::string& file, bool use_proxy) {
    ptr = config_new(file.c_str(), (int) use_proxy);
}

void mm::Config::get_vids(vid_cb callback, void* data) {
    config_get_vids(ptr, callback, data);
}

std::vector<mm::Video*>* mm::Config::get_vids_list() {
    std::vector<mm::Video*>* out = new std::vector<mm::Video*>;

    Videos* cvids = config_get_vids_list(ptr);

    out->reserve(cvids->length);
    for(int i=0 ; i<cvids->length ; i++){
        struct ::Video* vid = cvids->array[i];
        out->push_back(new mm::Video(vid));
    }

    return out;
}

mm::Net* mm::Config::net() {
    return new mm::Net(ptr->net);
}

struct Config* mm::Config::cptr() {
    return ptr;
}

mm::Config::~Config() {
    config_free(ptr);
}
