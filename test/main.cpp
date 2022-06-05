#include <Config.h>
#include <List.h>

#include <iostream>
#include <cstdio>


void vid_get(Video_t* vid, void* ptr){

    std::cout << vid->title << " -> " << vid->thumbnail << std::endl;

    video_free(vid);
}

void channel_get(Channel_t* channel, void* ptr){

    std::cout << channel->name << " -> " << channel->sub_count << std::endl;

    channel_free(channel);
}


int main() {
    Config* conf = config_new("/home/rhys/.config/yt_saves.json.small", 0);
    conf->use_threading = 1;

    config_get_vids(conf, vid_get, NULL);


    config_save(conf);
    config_free(conf);

    return 0;
}
