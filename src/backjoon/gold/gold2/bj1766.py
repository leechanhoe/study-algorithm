import heapq
import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
indegree = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]
for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

hq = []
ans = []
for i in range(1, N + 1):
    if indegree[i] == 0:
        heapq.heappush(hq, i)
while hq:
    now = heapq.heappop(hq)
    ans.append(now)
    for i in graph[now]:
        indegree[i] -= 1
        if indegree[i] == 0:
            heapq.heappush(hq, i)

print(*ans)