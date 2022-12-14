from Config import Config
from yt import net_set_req_func

import requests

conf = Config("/home/rhys/.config/yt_saves.json")

net_set_req_func(lambda x: requests.get(x).content.decode())

vids = conf.get_vid_list()

print(vids)
