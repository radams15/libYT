//
// Created by rhys on 13/02/2022.
//

#include "Util.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* strdup(const char *in) {
    unsigned int newlen = ((strlen(in))*sizeof(const char))+5;

    char* buf = malloc(newlen);

    strcpy(buf, in);

    return buf;
}

const char* read_file(const char* fname){
    char* buffer = NULL;
    long length;
    FILE* file = fopen(fname, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length);

        if(buffer) {
            fread(buffer, 1, length, file);
        }

        fclose (file);
    }

    return buffer;
}