#include <Config.h>
#include <List.h>

#include <iostream>
#include <cstdio>

#ifdef __APPLE__
#define COMMAND "open -a 'VLC'"
#elif defined(__unix__)
#define COMMAND "flatpak run com.github.rafostar.Clapper"
#else
#warning "Unknown OS! Will not be able to autoplay"
#define COMMAND "echo "
#endif

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

    /*List_t* vids = config_get_vids_list(conf);

    for(int i=0 ; i<vids->length ; i++){
        printf("%s\n", videos_get(vids, i)->title);
    }*/

    List_t* channels = channel_search_list(conf, "minecraft", 1);

    for(int i=0 ; i<channels->length ; i++){
        printf("%s\n", channels_get(channels, i)->name);
    }
    config_free(conf);

    return 0;
}
