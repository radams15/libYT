from Config import Config

conf = Config("/Users/rhys/Library/yt_saves.json")

vids = conf.get_vid_list()

print(vids)