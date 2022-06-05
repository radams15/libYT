//
// Created by Rhys on 01/03/2022.
//

#ifndef YT_LIST_H
#define YT_LIST_H


#ifdef __cplusplus
extern "C"{
#endif

typedef struct List {
    void** arry;
    int length;
} List_t;

void videos_free(List_t* vids);
void channels_free(List_t* channels);

int list_length(List_t* vids);
struct Video* videos_get(List_t* vids, int index);
struct Channel* channels_get(List_t* vids, int index);

#ifdef __cplusplus
}
#endif

#endif //YT_LIST_H
