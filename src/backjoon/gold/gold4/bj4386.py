import math

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parent[b] = a
    else:
        parent[a] = b

N = int(input())
parent = list(range(N + 1))
stars = []
edges = []
for _ in range(N):
    x, y = map(float, input().split())
    stars.append((x, y))

for i in range(N - 1):
    for j in range(i + 1, N):
        edges.append((math.sqrt((stars[i][0] - stars[j][0]) ** 2 + (stars[i][1] - stars[j][1]) ** 2), i, j))

edges.sort()
ans = 0
for d, x, y in edges:
    if find(x) != find(y):
        union(x, y)
        ans += d
print(round(ans, 2))