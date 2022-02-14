//
// Created by rhys on 13/02/2022.
//

#include "Channel.h"
#include "Util.h"
#include "Net.h"

#include <stdlib.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#define STR_EQ(a, b) (!xmlStrcmp(a, (const xmlChar *) b))

Channel* channel_new(const char* id) {
    Channel* out = malloc(sizeof(Channel));

    out->id = strdup(id);
    out->name = "";

    return out;
}

void channel_free(Channel* channel) {
    free(channel->id);
    if(strlen(channel->name) > 0){
        free(channel->name);
    }

    free(channel);
}

const char* channel_name(Channel* channel) {
    if(strlen(channel->name) == 0){
        const char* name = "TODO";
        channel->name = strdup("TODO");

    }

    return (const char*) channel->name;
}

void make_video(xmlNode* node, Video* vid, int level){
    for(xmlNode* i=node->children; i!=NULL; i=i->next){
        const xmlChar* key = i->name;

        if(STR_EQ(key, "group")){
            make_video(i, vid, level+1);
        } else if(STR_EQ(key, "link")){
            vid->link = ((char*) xmlGetProp(i, (const xmlChar*)"href"));
        } else if(STR_EQ(key, "published")){
            vid->publish_date = ((char*) xmlNodeGetContent(i));
        }else if(STR_EQ(key, "title")){
            vid->title = ((char*) xmlNodeGetContent(i));
        }
    }
}

int channel_get_vids(Channel *channel, channel_cb callback, void* data) {
    const char* url_base = "https://www.youtube.com/feeds/videos.xml?channel_id=";
    char* url = calloc(strlen(url_base) + strlen(channel->id) + 1, sizeof(char));
    strcpy(url, url_base);
    strcat(url, channel->id);

    const char* raw = net_get(url);

    free(url);

    xmlDoc* doc = NULL;
    xmlNode* root = NULL;

    if(!(doc = xmlReadMemory(raw, strlen(raw), "", "utf-8", NULL))){
        printf("error: could not parse data\n");
        return 1;
    }

    root = xmlDocGetRootElement(doc);

    for(root=root->children; root!=NULL; root=root->next){
        if(STR_EQ(root->name, "entry")){
            Video* v = video_new();

            v->channel_name = strdup(channel_name(channel));
            v->channel_id = strdup(channel->id);

            make_video(root, v, 0);

            callback(v, data);
        }
    }

    return 0;
}