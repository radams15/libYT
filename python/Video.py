import yt

from datetime import datetime

class Video:
    def __init__(self, ptr):
        self._ptr = ptr

    def id(self):
        return self._ptr.id

    def title(self):
        return self._ptr.title

    def channel_name(self):
        return self._ptr.channel_name

    def channel_id(self):
        return self._ptr.channel_id

    def published(self):
        return datetime.utcfromtimestamp(self._ptr.published)

    def playable(self, quality):
        return yt.video_get_playable(self._ptr, int(quality))

    def __repr__(self):
        return "{} - {}".format(self.channel_name(), self.title())

    def __del__(self):
        yt.video_free(self._ptr)