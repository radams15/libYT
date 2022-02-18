//
// Created by rhys on 13/02/2022.
//

#ifndef YOUTUBE_NET_H
#define YOUTUBE_NET_H

#include <stddef.h>
#include <stdlib.h>

#include "../src/main/Util.h"

#ifdef __cplusplus
extern "C"{
#endif

struct Net {
    const char* proxy;
    int use_proxy;
};

struct Net* net_new(int use_proxy);

typedef void (*stream_cb)(void*, size_t);

const char* net_get(struct Net* net, const char* url);

int net_stream(struct Net* net, const char* url, stream_cb stream_func);
	
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace mm{
    class Net{
    private:
        struct ::Net* ptr;
    public:
        explicit Net(struct ::Net* ptr);

        struct ::Net* cptr();
    };
}
#endif

#endif //YOUTUBE_NET_H
