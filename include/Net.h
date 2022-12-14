#ifndef LIBYT_NET
#define LIBYT_NET

typedef const char*(*req_func_t)(const char*);

const char* net_get(const char* url, int use_proxy, const char* proxy_url);
void net_set_req_func(req_func_t func);
#endif
