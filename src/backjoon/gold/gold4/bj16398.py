N = int(input())
adj = [list(map(int, input().split())) for _ in range(N)]
flow = []
for i in range(N):
    for j in range(i + 1, N):
        flow.append((adj[i][j], i, j))
flow.sort()
parent = list(range(N))


def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


def uni(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


cnt = 0
ans = 0
for cost, a, b in flow:
    if find(a) != find(b):
        uni(a, b)
        cnt += 1
        ans += cost
        if cnt == N - 1:
            break

print(ans)
