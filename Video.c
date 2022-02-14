//
// Created by rhys on 13/02/2022.
//

#include "Video.h"

#include <stdlib.h>
#include <string.h>

#define FREE_NOTNULL(a) if(strlen(a) > 0){ free((void*) a); }

void video_free(Video *video) {
    FREE_NOTNULL(video->link)
    FREE_NOTNULL(video->title)
    FREE_NOTNULL(video->channel_name)
    FREE_NOTNULL(video->channel_id)
    FREE_NOTNULL(video->publish_date)

    free(video);
}

Video *video_new() {
    Video* out = malloc(sizeof(Video));

    out->link = "";
    out->title = "";
    out->channel_name = "";
    out->channel_id = "";
    out->publish_date = "";

    return out;
}
