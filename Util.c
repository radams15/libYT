//
// Created by rhys on 13/02/2022.
//

#include "Util.h"

#include <stdlib.h>
#include <string.h>

char* strdup(const char *in) {
    unsigned int newlen = ((strlen(in))*sizeof(const char))+5;

    char* buf = malloc(newlen);

    strcpy(buf, in);

    return buf;
}
