//
// Created by rhys on 14/12/22.
//

#include <stdlib.h>
#include <stdio.h>

#include <curl/curl.h>
#include <string.h>

struct String_t {
    char* data;
    unsigned int length;
};

static size_t writefunc(void *ptr, size_t size, size_t nmemb, struct String_t* s) {
    size_t new_len = s->length + size*nmemb;

    s->data = realloc(s->data, new_len+1);

    if (s->data == NULL) {
        printf("realloc() failed!\n");
        exit(EXIT_FAILURE);
    }

    memcpy(s->data+s->length, ptr, size*nmemb);
    ((char*)s->data)[new_len] = 0;
    s->length = new_len;

    return size*nmemb;
}

const char* curl_req_get(const char* url){
    CURL *curl;
    CURLcode res;

    struct String_t out;
    out.data = malloc(1);
    out.length = 0;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

#ifdef LOCAL_CERT
        curl_easy_setopt(curl, CURLOPT_CAINFO, "curl-ca-bundle.crt");
#endif
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);

        return out.data;
    }

    return NULL;
}