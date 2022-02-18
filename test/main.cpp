#include <Config.h>

#include <iostream>

#ifdef __APPLE__
#define COMMAND "open -a 'VLC'"
#elif defined(__unix__)
#define COMMAND "flatpak run com.github.rafostar.Clapper"
#else
#warning "Unknown OS! Will not be able to autoplay"
#define COMMAND "echo "
#endif

void vid_got(struct Video* vid, void* data){
    std::cout << vid->channel_name << " -> " << vid->title << std::endl;
}

int main() {
    mm::Config conf("/Users/rhys/Library/yt_saves.json", true);
    //mm::Config conf("yt_saves.json", true);

    std::vector<mm::Video*>* vids = conf.get_vids_list();

    for(int i=0 ; i<vids->size() ; i++){
        mm::Video* vid = vids->at(i);

        std::cout << vid->channel_name() << " -> " << vid->title() << std::endl;
    }

    return 0;
}
