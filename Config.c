//
// Created by rhys on 13/02/2022.
//

#include "Config.h"
#include "Util.h"

#include <stdlib.h>

Config* config_new(const char* file) {
    Config* out = malloc(sizeof(Config));

    out->file = strdup(file);
    out->quality = 480;
    out->subs = malloc(sizeof(Subs));

    out->subs->array = malloc(1);
    out->subs->length = 0;

    return out;
}

void config_free(Config *conf) {
    free((void*) conf->file);
    if(conf->subs->length > 0) {
        for(int i=0 ; i<conf->subs->length ; i++){
            channel_free(conf->subs->array[i]);
        }
        free(conf->subs->array);
    }
    free(conf->subs);
}

void config_subs_add(Config* conf, Channel* channel) {
    conf->subs->length++;

    conf->subs->array = realloc(conf->subs->array, conf->subs->length*sizeof(Channel*));

    conf->subs->array[conf->subs->length-1] = channel;
}
