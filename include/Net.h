//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_NET_H
#define YOUTUBE_NET_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*stream_cb)(void*, size_t);

const char* net_get(const char* url);

int net_stream(const char* url, stream_cb stream_func);
	
#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_NET_H
