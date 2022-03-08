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

int main() {
    Config* conf = config_new("/Users/rhys/Library/yt_saves.json", 1);

    Videos* vids = config_get_vids_list(conf);

    for(int i=0 ; i<vids->length ; i++){
        Video* vid = videos_get(vids, i);

        std::cout << vid->channel_name << " -> " << vid->title << std::endl;
    }

    videos_free(vids);

    config_free(conf);

    return 0;
}
