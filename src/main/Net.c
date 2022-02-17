//
// Created by rhys on 13/02/2022.
//

#include <Net.h>

#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>


struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(1);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}

size_t stream_write_cb(void* contents, size_t size, size_t nmemb, void* userp){
	size_t len = size*nmemb;
	
	((stream_cb) userp)(contents, len);

    return len;
}

const char* net_get(const char* url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        struct string s;
        init_string(&s);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        res = curl_easy_perform(curl);
		
        /* always cleanup */
        curl_easy_cleanup(curl);

        return s.ptr;
    }

    return NULL;
}

int net_stream(const char* url, stream_cb stream_func){
    CURL *curl;
    CURLcode res;
	int out = -1;
	
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, stream_write_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) stream_func);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &out);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        res = curl_easy_perform(curl);
		
        /* always cleanup */
        curl_easy_cleanup(curl);

    }
	
    return out;
}
