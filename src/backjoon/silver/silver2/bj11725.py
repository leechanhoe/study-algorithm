import sys
sys.setrecursionlimit(10 ** 6)
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
g = [[] for _ in range(N + 1)]
for i in range(N - 1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

visited = [0] * (N + 1)

def dps(n):
    for i in g[n]:
        if not visited[i]:
            visited[i] = n
            dps(i)
dps(1)
for i in visited[2:]:
    print(i)