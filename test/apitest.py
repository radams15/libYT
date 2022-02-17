import requests
import json

vid = "eB2OpurOFhk"

BASE = "http://vid.puffyan.us"

def get_api(path):
    url = BASE+path

    res = requests.get(url)

    if res.status_code == 200:
        return res.content

    return None

data = json.loads(get_api("/api/v1/channels/UCbguawtJlHjxXzdAskubQVg"))

for d in data["latestVideos"]:
    print(d)