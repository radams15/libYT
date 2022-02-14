#include <stdio.h>
#include <string.h>
#include "Channel.h"
#include "Config.h"

void got_vid(Video* vid, void* data){
    if(strlen(vid->title) > 0) {
        printf("Title: %s\n", vid->channel_name);
        video_free(vid);
    }
}

int main() {
    Config* conf = config_new("/home/rhys/.local/share/yt_saves.json");

    Channel* c = channel_new("UClY9pvqTLAxmz3vD1r-PxUA");

    config_subs_add(conf, c);

    config_free(conf);

    //channel_get_vids(c, &got_vid, "Test1");

    return 0;
}
