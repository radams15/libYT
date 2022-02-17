#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Config.h>
#include <Net.h>

#ifdef __APPLE__
#define COMMAND "open -a 'VLC'"
#elif defined(__unix__)
#define COMMAND "flatpak run com.github.rafostar.Clapper"
#else
#warning "Unknown OS! Will not be able to autoplay"
#define COMMAND "echo "
#endif

int main() {
    struct Config* conf = config_new("yt_saves.json");

    struct Videos* vids = config_get_vids_list(conf);

    for(int i=0 ; i<vids->length ; i++){
        printf("[%d]: Title: %s\n", i, vids->array[i]->title);
    }

    int choice;

    printf("Choice: ");
    scanf("%d", &choice);

    if(choice > 0 && choice < vids->length) {
        const char* url = video_get_playable(vids->array[choice], conf);
		
		printf("url: %s\n", url);
		
	//printf("Data: %s\n", net_get(url));

	/*char* command = malloc((strlen(COMMAND)+strlen(url)+10));
        sprintf(command, COMMAND " '%s'&", url);

        printf("%s\n", command);
	    system(command);

        free(command);
        free((void*) url);*/
    }

    videos_free(vids);

    config_free(conf);

    return 0;
}
