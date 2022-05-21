//
// Created by rhys on 13/02/2022.
//

#include "Util.h"
#include "Videos.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* strdup(const char *in) {
    unsigned int newlen = ((strlen(in))*sizeof(const char))+5;

    char* buf = malloc(newlen);

    strcpy(buf, in);

    return buf;
}

void config_vid_list_appender(Video_t* vid, void* ptr){
    Videos_t* vids = ptr;

    vids->length++;
    vids->arry = realloc(vids->arry, vids->length * sizeof(struct Video*));

    vids->arry[vids->length - 1] = vid;
}

const char* read_file(const char* fname){
    char* buffer;
    long length;
    FILE* file = fopen(fname, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length+10);

        if(buffer) {
            fread(buffer, 1, length, file);
        }

        fclose (file);
    }

    return buffer;
}