import requests
def getBusTime(startX, startY, endX, endY): # X = 경도 Y = 위도
    url = "https://apis.openapi.sk.com/transit/routes/sub"

    payload = {
        "startX": str(startX),
        "startY": str(startY),
        "endX": str(endX),
        "endY": str(endY),
        "format": "json",
        "count": 10
    }
    headers = {
        "accept": "application/json",
        "content-type": "application/json",
        "appKey": "e8wHh2tya84M88aReEpXCa5XTQf3xgo01aZG39k5"
    }

    response = requests.post(url, json=payload, headers=headers)
    time = 0
    try:
        response.json()["metaData"]["plan"]["itineraries"].sort(key=lambda x : x['totalTime'])
        time = response.json()["metaData"]["plan"]["itineraries"][2]['totalTime']
        print(response.json()["metaData"]["plan"]["itineraries"])
    except:
        print(response.json()['result']['message'])
    finally:
        return time / 60
    return time / 60
print(f"예상시간 : {getBusTime(126.9563751, 37.49550629, 126.9493256, 37.46709442)}분")