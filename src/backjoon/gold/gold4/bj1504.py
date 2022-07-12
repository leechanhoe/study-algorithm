import sys
import heapq
input = lambda : sys.stdin.readline().rstrip()
INF = sys.maxsize

N, E = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for i in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))
v1, v2 = map(int, input().split())

def dijkstra(start):
    hq = []
    dist = [INF] * (N + 1)
    heapq.heappush(hq, (start, 0))
    dist[start] = 0
    while hq:
        now, cost = heapq.heappop(hq)
        for e, cost in graph[now]:
            wei = cost + dist[now]
            if dist[e] > wei:
                dist[e] = wei
                heapq.heappush(hq, (e, wei))
    return dist

one = dijkstra(1)
v1_ = dijkstra(v1)
v2_ = dijkstra(v2)
ans = min(one[v1] + v1_[v2] + v2_[N], one[v2] + v2_[v1] + v1_[N])
print(ans if ans < INF else -1)