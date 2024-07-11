import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
arr = sorted(list(map(int, input().split())))

visit = [False] * N
ans = []

def dfs(depth, now_i):
    if depth == 0:
        print(*ans)
        return
    
    for i in range(now_i + 1, N):
        if not visit[i]:
            visit[i] = True
            ans.append(arr[i])
            dfs(depth - 1, i)
            ans.pop()
            visit[i] = False

dfs(M, -1)