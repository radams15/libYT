from yt import *

conf = config_new("yt_saves.json")

vids = config_get_vids_list(conf)

for i in range(0, vids.length):
    vid = videos_get(vids, i)
    print(video_get_playable(vid, conf.quality))

videos_free(vids)

config_free(conf)