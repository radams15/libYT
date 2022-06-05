
























const char* net_get(const char* url, int use_proxy, const char* proxy_url);



typedef struct Video {
    char* id;
    char* title;
    char* channel_name;
    char* channel_id;
    long published;
} Video_t;

Video_t* video_new();
void video_free(Video_t* video);



typedef struct List {
    void** arry;
    int length;
} List_t;

void videos_free(List_t* vids);
void channels_free(List_t* channels);

int list_length(List_t* vids);
struct Video* videos_get(List_t* vids, int index);
struct Channel* channels_get(List_t* vids, int index);






typedef void (*vid_cb)(Video_t*, void*);

typedef struct Config{
    const char* fname;
    int quality;
    struct List* subs;
    const char* invidious_inst;
    int use_threading;
    int use_proxy;
    const char* proxy_url;
} Config_t;



typedef struct Channel {
    char* id;
    char* name;
    long sub_count;
    long video_count;
} Channel_t;

typedef struct Channels {
    Channel_t** arry;
    long length;
} Channels_t;

typedef void (*channel_cb)(Channel_t*, void*);




Channel_t* channel_new(const char* id);

Channel_t* channel_new_from_name(const char* name, Config_t* conf);

void channel_search(Config_t* conf, const char* query, int page, channel_cb callback, void* data);
List_t* channel_search_list(Config_t* conf, const char* query, int page);

const char* channel_name(Channel_t* channel, Config_t* conf);

int channel_get_vids(Channel_t* channel, Config_t* conf, vid_cb callback, void* data);
List_t* channel_get_vids_list(Channel_t* channel, Config_t* conf);

void channel_free(Channel_t* channel);


Config_t* config_new(const char* fname, int use_proxy);

void config_subs_add(Config_t* conf, Channel_t* channel);
void config_subs_rm(Config_t* conf, Channel_t* channel);

void config_save(Config_t* conf);

List_t* config_get_vids_list(Config_t* conf);

int config_get_vids(Config_t* conf, vid_cb callback, void* data);

const char* video_get_playable(Video_t* video, Config_t* conf);

void config_free(Config_t* conf);

void config_video_search(Config_t* conf, const char* query, int page, vid_cb callback, void* data);
List_t* config_video_search_list(Config_t* conf, const char* query, int page);

