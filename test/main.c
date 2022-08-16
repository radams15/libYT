#include <Config.h>

#include <stdio.h>

void vid_get(Video_t* vid, void* ptr){

    printf("%s -> %s\n", vid->title, vid->channel_name);

    video_free(vid);
}

void channel_get(Channel_t* channel, void* ptr){
    printf("%s -> %d\n", channel->name, channel->sub_count);

    channel_free(channel);
}

int main() {
    Config_t* conf = config_new("sdgsnkgsdukigds", 0);
    conf->use_threading = 1;

    config_get_vids_list(conf);

    config_save(conf);
    config_free(conf);

    return 11;
}
