//
// Created by rhys on 13/02/2022.
//

#include "Util.h"
#include "List.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#if __unix__
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#elif WINDOWS
#include <windows.h>
#include <lmcons.h>
#endif

/*char* strdup(const char *in) {
    unsigned int newlen = ((strlen(in))*sizeof(const char))+5;

    char* buf = malloc(newlen);

    strcpy(buf, in);

    return buf;
}*/

void config_video_list_appender(Video_t* vid, void* ptr){
    List_t* vids = ptr;

    vids->length++;
    vids->arry = realloc(vids->arry, vids->length * sizeof(struct Video*));

    vids->arry[vids->length - 1] = vid;
}

void config_channel_list_appender(Channel_t *vid, void *ptr) {
    List_t* vids = ptr;

    vids->length++;
    vids->arry = realloc(vids->arry, vids->length * sizeof(struct Channel*));

    vids->arry[vids->length - 1] = vid;
}

int path_exists(const char* path){
#if __unix__
    struct stat sb;
    if (stat(path, &sb) == 0){
        return 1;
    }
    return 0;
#elif WINDOWS
    DWORD ftyp = GetFileAttributesA(path);
    if (ftyp == INVALID_FILE_ATTRIBUTES){
        return 0;
    }

    if (ftyp){
        return 1;
    }

    return 0;
#else
#error Cannot determine OS (dirExists)!
#endif
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