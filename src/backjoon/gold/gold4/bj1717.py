import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)
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

N, M = map(int, input().split())
parent = list(range(N + 1))
for _ in range(M):
    c, a, b = map(int, input().split())
    if c:
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")
    else:
        union(a, b)