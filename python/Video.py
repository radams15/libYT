import yt

class Video:
    def __init__(self, ptr):
        self._ptr = ptr

    def link(self):
        return self._ptr.link

    def title(self):
        return self._ptr.title

    def channel_name(self):
        return self._ptr.channel_name

    def channel_id(self):
        return self._ptr.channel_id

    def publish_date(self):
        return self._ptr.publish_date

    def playable(self, quality):
        return yt.video_get_playable(self._ptr, int(quality))

    def __del__(self):
        yt.video_free(self._ptr)