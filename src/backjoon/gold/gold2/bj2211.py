import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()


def dijkstra(start):
    q = []
    dist[start] = 0
    heapq.heappush(q, (0, start))

    while q:
        d, now = heapq.heappop(q)
        if dist[now] < d:
            continue

        for next, cost in adj[now]:
            ncost = d + cost

            if ncost < dist[next]:
                parent[next] = now
                dist[next] = ncost
                heapq.heappush(q, (ncost, next))


N, M = map(int, input().split())
INF = int(1e9)
dist = [INF] * (N + 1)
parent = [0] * (N + 1)
adj = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

dijkstra(1)

print(N - 1)
for i in range(2, N + 1):
    print(i, parent[i])
