#include <Net.h>

#include <request.h>

const char* net_get(const char* url, int use_proxy, const char* proxy_url){
	Res_t* res = req_get(url, NULL);
	
	return res->data;
}
