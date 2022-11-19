import sys
from collections import deque
input = lambda : sys.stdin.readline()

def bfs(mid):
    visit[start] = 1
    q = deque()
    q.append(start)

    while q:
        now = q.popleft()
        if now == end:
            return True
        for next, weight in adj[now]:
            if not visit[next] and mid <= weight:
                q.append(next)
                visit[next] = True
    return False

N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]

for i in range(M):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

start, end = map(int, input().split())
lo = 1
hi = 1000000000

while lo <= hi:
    visit = [False] * (N + 1)
    mid = (lo + hi) // 2

    if bfs(mid):
        lo = mid + 1
    else:
        hi = mid - 1
    
print(hi)