





















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



typedef struct Videos {
    struct Video** arry;
    int length;
} Videos_t;

void videos_free(Videos_t* vids);

Video_t* videos_get(Videos_t* vids, int index);






typedef void (*vid_cb)(Video_t*, void*);

typedef struct Config{
    const char* fname;
    int quality;
    struct Subs* subs;
    const char* invidious_inst;
    int use_threading;
    int use_proxy;
    const char* proxy_url;
} Config_t;



typedef struct Channel{
    char* id;
    char* name;
} Channel_t;




Channel_t* channel_new(const char* id);

Channel_t* channel_new_from_name(const char* name, Config_t* conf);

const char* channel_name(Channel_t* channel, Config_t* conf);

int channel_get_vids(Channel_t* channel, Config_t* conf, vid_cb callback, void* data);

void channel_free(Channel_t* channel);


typedef struct Subs{
    Channel_t** arry;
    int length;
} Subs_t;

Config_t* config_new(const char* fname, int use_proxy);

void config_subs_add(Config_t* conf, Channel_t* channel);

void config_save(Config_t* conf);

Videos_t* config_get_vids_list(Config_t* conf);

int config_get_vids(Config_t* conf, vid_cb callback, void* data);

const char* video_get_playable(Video_t* video, Config_t* conf);

void config_free(Config_t* conf);

