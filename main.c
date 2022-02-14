#include <stdio.h>
#include "Config.h"

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
        printf("Chose: %s\n", vids->array[choice]->title);
    }

    videos_free(vids);

    config_free(conf);

    return 0;
}
