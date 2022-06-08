from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
user = [set() for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    user[a].add(b)
    user[b].add(a)

min = 987654321
ans = 0
for i in range(1, n + 1):
    visited = [False] * (n + 1)
    visited[i] = True
    dq = deque()
    kevin = 0
    dq.append((i, 0))

    while dq:
        fri, d = dq.popleft()
        for fr in user[fri]:
            if not visited[fr]:
                dq.append((fr, d + 1))
                visited[fr] = True
                kevin += d + 1

    if min > kevin:
        ans = i
        min = kevin

print(ans)