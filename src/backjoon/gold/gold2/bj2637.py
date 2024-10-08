N = int(input())
M = int(input())
adj = [[] for _ in range(N + 1)]
needs = [[0] * (N + 1) for _ in range(N + 1)]
degree = [0] * (N + 1)
zero = []

for _ in range(M):
    x, y, k = map(int, input().split())
    adj[y].append((x, k))
    degree[x] += 1

for i in range(1, N + 1):
    if degree[i] == 0:
        zero.append(i)

while zero:
    now = zero.pop()
    for next, need in adj[now]:
        if needs[now].count(0) == N + 1:
            needs[next][now] += need
        else:
            for i in range(1, N + 1):
                needs[next][i] += needs[now][i] * need

        degree[next] -= 1
        if degree[next] == 0:
            zero.append(next)

for i, x in enumerate(needs[N]):
    if x > 0:
        print(i, x)
