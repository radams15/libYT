#include <Config.h>
#include <Videos.h>

#include <iostream>

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
}

int main() {
    Config* conf = config_new("/home/rhys/.local/share/yt_saves.json", 1);

    config_get_vids(conf, vid_get, NULL);

    config_free(conf);

    return 0;
}
