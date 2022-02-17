//
// Created by rhys on 13/02/2022.
//

#include "Video.h"
#include "Net.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Constants.h"

#include "Config.h"

#define FREE_NOTNULL(a) if(strlen(a) > 0){ free((void*) a); }

void video_free(struct Video *video) {
    FREE_NOTNULL(video->link)
    FREE_NOTNULL(video->title)
    FREE_NOTNULL(video->channel_name)
    FREE_NOTNULL(video->channel_id)
    FREE_NOTNULL(video->publish_date)

    free(video);
}

struct Video* video_new() {
    struct Video* out = malloc(sizeof(Video));

    out->link = "";
    out->title = "";
    out->channel_name = "";
    out->channel_id = "";
    out->publish_date = "";

    return out;
}

const char* video_get_playable(struct Video* video, struct Config* conf) {
    unsigned int len = strlen(BASE_URL) + strlen(video->link) + 32;

    char* url = malloc((len*sizeof(char))+5);

    sprintf(url, BASE_URL "stream.php?url=%s&quality=best[height<=%d]", video->link, conf->quality);

    const char* stream_url = net_get(url);

    free(url);

    return stream_url;
}
