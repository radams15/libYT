//
// Created by Rhys on 01/03/2022.
//

#ifndef YT_VIDEOS_H
#define YT_VIDEOS_H

#include <Video.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct Videos {
    struct Video** arry;
    int length;
} Videos_t;

void videos_free(Videos_t* vids);

Video_t* videos_get(Videos_t* vids, int index);

#ifdef __cplusplus
}
#endif

#endif //YT_VIDEOS_H
