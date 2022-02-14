import yt

from Channel import Channel
from Video import Video

class Config:
    def __init__(self, file):
        self._ptr = yt.config_new(file)

    def file(self):
        return self._ptr.file

    def quality(self):
        return self._ptr.quality

    def add_sub(self, channel: Channel):
        yt.config_subs_add(self._ptr, channel._ptr)

    def get_vid_list(self):
        vids = yt.config_get_vids_list(self._ptr)

        out = [
            Video(
                yt.videos_get(vids, x)
            )
            for x in range(0, vids.length)
        ]

        return sorted(out, key=lambda x: x.publish_date())

    def __del__(self):
        yt.config_free(self._ptr)