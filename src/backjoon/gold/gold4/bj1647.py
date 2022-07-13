import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
parent = list(range(N + 1))

def find_root(x):
    if x != parent[x]:
        parent[x] = find_root(parent[x])
    return parent[x]

def union(a, b):
    a = find_root(a)
    b = find_root(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

load = []
for i in range(M):
    load.append(tuple(map(int, input().split())))
load.sort(key=lambda x : x[2])

ans = 0
load_num = 0 # 최소 신장 트리에서 제일 긴 간선을 제거하면 된다
for i in range(M):
    a, b, c = load[i]
    if find_root(a) != find_root(b):
        union(a, b)
        ans += c
        load_num += 1
    if load_num == N - 2:
        break
        
print(ans)