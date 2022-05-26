#include <Config.h>
#include <List.h>

#include <iostream>
#include <cstdio>


void vid_get(Video_t* vid, void* ptr){

    std::cout << vid->channel_name << " -> " << vid->title << std::endl;

    video_free(vid);
}

void channel_get(Channel_t* channel, void* ptr){

    std::cout << channel->name << " -> " << channel->sub_count << std::endl;

    channel_free(channel);
}


int main() {
    Config* conf = config_new("/home/rhys/.config/yt_saves.json.small", 0);
    conf->use_threading = 1;

    for(int i=0 ; i<conf->subs->length ; i++){
        printf("%s\n", channel_name(channels_get(conf->subs, i), conf));
    }

    /*List_t* channels = channel_search_list(conf, "techmoan", 1);

    for(int i=0 ; i<channels->length ; i++){
        printf("%s\n", channels_get(channels, i)->name);
    }*/


    config_save(conf);
    config_free(conf);

    return 0;
}
