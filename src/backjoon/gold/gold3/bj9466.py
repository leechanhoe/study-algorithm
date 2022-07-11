import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 7)

def dfs(x):
    global ans
    visit[x] = True
    cycle.append(x)
    if visit[stu[x]]:
        if stu[x] in cycle:
            ans += cycle[cycle.index(stu[x]):]
    else:
        dfs(stu[x])

for _ in range(int(input())):
    N = int(input())
    stu = [0] + [*map(int, input().split())]
    ans = []
    visit = [False] * (N + 1)

    for i in range(1, N + 1):
        if not visit[i]:
            cycle = []
            dfs(i)

    print(N - len(ans))