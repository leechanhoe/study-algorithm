import sys
import heapq
input = lambda : sys.stdin.readline().rstrip()
INF = int(1e9)

def dijkstra(start):
    dist = [INF] * (N + 1)
    dist[start] = 0
    hq = [(start, 0)]
    while hq:
        now, cost = heapq.heappop(hq)
        if cost > dist[now]:
            continue
        for next, c in graph[now]:
            nc = c + dist[now]
            if nc < dist[next]:
                dist[next] = nc
                heapq.heappush(hq, (next, nc))
    return dist

N, M, X = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

back = dijkstra(X)
ans = 0
for i in range(1, N + 1):
    ans = max(ans, dijkstra(i)[X] + back[i])
print(ans)