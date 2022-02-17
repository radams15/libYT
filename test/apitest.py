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

data = json.loads(get_api("/api/v1/videos/{}".format(vid)))

for d in sorted(data["formatStreams"], key=lambda x: x["qualityLabel"]):
    print(d["qualityLabel"])