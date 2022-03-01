































struct Config;

struct Video {
    char* id;
    char* title;
    char* channel_name;
    char* channel_id;
    int published;
};

struct Video* video_new();
void video_free(struct Video* video);

const char* video_get_playable(struct Video* video, struct Config* conf);






typedef void (*vid_cb)(struct Video*, void*);

struct Channel{
    char* id;
    char* name;
};

struct Channel* channel_new(const char* id);

struct Channel* channel_new_from_name(const char* name, struct Config* conf);

const char* channel_name(struct Channel* channel, struct Config* conf);

int channel_get_vids(struct Channel* channel, struct Config* conf, vid_cb callback, void* data);

void channel_free(struct Channel* channel);



typedef void (*stream_cb)(void*, int);

const char* net_get(const char* url, int use_proxy, const char* proxy);

int net_stream(const char* url, stream_cb stream_func, int use_proxy, const char* proxy);






struct Subs{
    struct Channel** array;
    int length;
};

struct Config{
    const char* file;
    int quality;
    struct Subs* subs;
    const char* invidious_inst;
    int use_threading;
    int use_proxy;
    const char* proxy_url;
};

struct Videos {
    struct Video** array;
    int length;
};

struct Config* config_new(const char* file, int use_proxy);

void config_subs_add(struct Config* conf, struct Channel* channel);

void config_save(struct Config* conf);

struct Videos* config_get_vids_list(struct Config* conf);
void videos_free(struct Videos* vids);

struct Video* videos_get(struct Videos* vids, int index);

int config_get_vids(struct Config* conf, vid_cb callback, void* data);

void config_free(struct Config* conf);


