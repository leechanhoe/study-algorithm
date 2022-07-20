import sys
input = lambda : sys.stdin.readline().rstrip()

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

N = int(input())
parent = list(range(N))
planets = [[i] + list(map(int, input().split())) for i in range(N)]

xsort = sorted(planets, key=lambda x : x[1])
ysort = sorted(planets, key=lambda x : x[2])
zsort = sorted(planets, key=lambda x : x[3])
edge = [] 
for i in range(1, N): # edge는 (a = 출발노드, b = 도착노드, c = 비용)으로 이루어짐 
    edge.append((xsort[i][0], xsort[i-1][0], xsort[i][1] - xsort[i-1][1]))
    edge.append((ysort[i][0], ysort[i-1][0], ysort[i][2] - ysort[i-1][2]))
    edge.append((zsort[i][0], zsort[i-1][0], zsort[i][3] - zsort[i-1][3]))
edge.sort(key=lambda x : x[2])

ans = 0
for a, b, cost in edge:
    if find(a) != find(b):
        union(a, b)
        ans += cost
print(ans)