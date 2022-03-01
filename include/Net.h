//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_NET_H
#define YOUTUBE_NET_H

#define size_t int

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*stream_cb)(void*, size_t);

const char* net_get(const char* url, int use_proxy, const char* proxy);

int net_stream(const char* url, stream_cb stream_func, int use_proxy, const char* proxy);

#ifdef __cplusplus
}
#endif

#endif //YOUTUBE_NET_H
