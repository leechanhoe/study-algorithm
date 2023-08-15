N, K = map(int, input().split())
kit = list(map(int, input().split()))
visit = [0] * N
ans = 0

def dfs(n, now, visit):
    global ans
    if(n == N):
        ans += 1

    for i in range(N):
        next = now + kit[i] - K
        if not visit[i] and 500 <= next:
            visit[i] = True
            dfs(n + 1, next, visit)
            visit[i] = False

dfs(0, 500, visit)
print(ans)