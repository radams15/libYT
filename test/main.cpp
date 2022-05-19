#include <Config.h>
#include <Videos.h>

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


class Test{
public:
    void GetVid(Video_t* vid){
        std::cout << vid->channel_name << " -> " << vid->title << std::endl;
    }
};

void vid_get(Video_t* vid, void* ptr){
    Test* test = (Test*) ptr;

    test->GetVid(vid);

    video_free(vid);
}

int main() {
    Config* conf = config_new("/home/rhys/.config/yt_saves.json.small", 0);
    conf->use_threading = 1;

    Videos_t* vids = config_get_vids_list(conf);

    for(int i=0 ; i<vids->length ; i++){
        printf("%lu\n", vids->arry[i]->published);
    }

    config_free(conf);

    return 0;
}
