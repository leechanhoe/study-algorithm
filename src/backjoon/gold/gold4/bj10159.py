import sys

input = lambda: sys.stdin.readline().rstrip()

N = int(input())
M = int(input())
INF = 987654321
dist = [[0] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    dist[a][b] = 1

for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if dist[i][k] and dist[k][j]:
                dist[i][j] = 1

for i in range(1, N + 1):
    cnt = 0
    for j in range(1, N + 1):
        if i == j:
            continue

        if not dist[i][j] and not dist[j][i]:
            cnt += 1

    print(cnt)
