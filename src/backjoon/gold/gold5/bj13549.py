import heapq

N, K = map(int, input().split())

def dijkstra(start):
    INF = 987654321
    distance = [INF] * 100001
    distance[start] = 0
    hq = [(0, start)]

    while hq:
        cost, now = heapq.heappop(hq)      
        if now == K:
            return cost
        if distance[now] < cost:
            continue
        if now > K:
            distance[K] = cost + (now - K)
            heapq.heappush(hq, (cost + (now - K), K))
            continue

        if now <= 100000 and cost + 1 < distance[now + 1]:
            distance[now + 1] = cost + 1
            heapq.heappush(hq, (cost + 1, now + 1))
        if now and cost + 1 < distance[now - 1]:
            distance[now - 1] = cost + 1
            heapq.heappush(hq, (cost + 1, now - 1))
        if now <= 50000 and now and cost < distance[now * 2]:
            distance[now * 2] = cost
            heapq.heappush(hq, (cost, now * 2))

print(dijkstra(N))