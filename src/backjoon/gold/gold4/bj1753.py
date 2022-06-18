import sys
import heapq
input = lambda : sys.stdin.readline().rstrip()
INF = 987654321

V, E = map(int, input().split())
start = int(input())
graph = [[] for _ in range(V + 1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
distance = [INF] * (V + 1)

def dijkstra(start):
    hq = []
    heapq.heappush(hq, (0, start))
    distance[start] = 0
    while hq:
        dist, now = heapq.heappop(hq)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(hq, (cost, i[0]))

dijkstra(start)
for i in range(1, V + 1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])