import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
N, M = map(int, input().split())

adj = [[False] * (N + 1) for _ in range(1 + N)]
for _ in range(M):
    a, b = map(int, input().split())
    adj[a][b] = adj[b][a] = True

chk = [False] * (N + 1)
ans = 0

def dfs(i):
    chk[i] = True
    for j in range(1, N + 1):
        if adj[i][j] and not chk[j]:
            dfs(j)

for i in range(1, N + 1):
    if(not chk[i]):
        dfs(i)
        ans += 1
print(ans)