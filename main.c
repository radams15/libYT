#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Config.h"

#ifdef __APPLE__
#define COMMAND ""
#elif defined(__unix__)
#define COMMAND "flatpak run com.github.rafostar.Clapper"
#else
#warning "Unknown OS! Will not be able to autoplay"
#define COMMAND "echo "
#endif

int main() {
    Config* conf = config_new("/home/rhys/.local/share/yt_saves.json");

    Videos* vids = config_get_vids_list(conf);

    for(int i=0 ; i<vids->length ; i++){
        printf("[%d]: Title: %s\n", i, vids->array[i]->title);
    }

    int choice;

    printf("Choice: ");
    scanf("%d", &choice);

    if(choice > 0 && choice < vids->length) {
        const char* url = video_get_playable(vids->array[choice], conf->quality);

        char* command = malloc((strlen(COMMAND)+strlen(url)+10));
        sprintf(command, COMMAND " '%s'", url);

        printf("%s\n", command);

        free(command);
        free(url);
    }

    videos_free(vids);

    config_free(conf);

    return 0;
}
