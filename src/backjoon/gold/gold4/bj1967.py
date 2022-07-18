import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)

N = int(input())
tree = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    parent, child, weight = list(map(int, input().split()))
    tree[parent].append((child, weight))
    tree[child].append((parent, weight))

def dfs(start, dist):
    for e, d in tree[start]:
        if dist[e] == 0:
            dist[e] = dist[start] + d
            dfs(e, dist)
# 트리의 지름은 임의의 노드 x 에서 가장 먼 노드 y를 구한 후
# y에서 가장 먼 노드 z를 구하면, y와 z의 거리가 트리의 지름이다. 
dist = [0] * (N + 1)
dfs(N, dist)
dist[N] = 0
max_ = 0
max_index = 0
for i, d in enumerate(dist):
    if max_ < d:
        max_ = d
        max_index = i

dist = [0] * (N + 1)
dfs(max_index, dist)
dist[max_index] = 0
print(max(dist))