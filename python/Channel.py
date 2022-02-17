import yt

class Channel:
    def __init__(self, id):
        self._ptr = yt.channel_new(id)

    def id(self):
        return self._ptr.id

    def name(self):
        return yt.channel_name(self._ptr)

    def __del__(self):
        yt.channel_free(self._ptr)