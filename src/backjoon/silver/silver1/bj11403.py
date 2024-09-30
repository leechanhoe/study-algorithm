N = int(input())
INF = 987654321
dist = [[INF] * N for _ in range(N)]

for i in range(N):
    inpu = list(map(int, input().split()))
    for j in range(N):
        if inpu[j]:
            dist[i][j] = 1

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(N):
    for j in range(N):
        if dist[i][j] < INF:
            print(1, end=" ")
        else:
            print(0, end=" ")
    print()