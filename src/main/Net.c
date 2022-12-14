#include <Net.h>
#include <stddef.h>
#include <stdio.h>

static req_func_t req_func = NULL;

const char* net_get(const char* url, int use_proxy, const char* proxy_url){
    if(req_func == NULL){
        fprintf(stderr, "Error getting data: no req_func defined.\n");
        return "";
    }

	return req_func(url);
}

void net_set_req_func(req_func_t func) {
    req_func = func;
}
