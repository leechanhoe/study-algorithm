import sys
from heapq import heappush, heappop
input = lambda : sys.stdin.readline().rstrip()
INF = 987654321

V, E = map(int, input().split())
start = int(input())
graph = [[] for _ in range(V + 1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
distance = [INF] * (V + 1)

pq = []
heappush(pq, (0, start))
distance[start] = 0
while pq:
    cost, now = heappop(pq)
    if distance[now] < cost:
        continue
    
    for next, c in graph[now]:
        ncost = cost + c
        if ncost < distance[next]:
            heappush(pq, (ncost, next))
            distance[next] = ncost

for i in range(1, V + 1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])