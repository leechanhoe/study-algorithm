N = int(input())
INF = 987654321
adj = [[INF] * (N + 1) for _ in range(N + 1)]
while 1:
    a, b = map(int, input().split())
    if a == b == -1:
        break

    adj[a][b] = 1
    adj[b][a] = 1

for k in range(1, N + 1):
    for i in range(1, N + 1):
        adj[i][i] = 0
        for j in range(1, N + 1):
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])

min_ = INF
for i in range(1, N + 1):
    min_ = min(min_, max(adj[i][1:]))

ans = []
for i in range(1, N + 1):
    if max(adj[i][1:]) == min_:
        ans.append(i)

ans.sort()
print(min_, len(ans))
print(*ans)
