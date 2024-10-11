import sys

sys.setrecursionlimit(10**7)

input = lambda: sys.stdin.readline().rstrip()

N, M, K = map(int, input().split())
candy = [0] + list(map(int, input().split()))
adj = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)


def dfs(now):
    visited[now] = True
    cnt = 1
    cand = candy[now]
    for next in adj[now]:
        if not visited[next]:
            ncnt, ncand = dfs(next)
            cnt += ncnt
            cand += ncand

    return cnt, cand


ans = 0
visited = [False] * (N + 1)
nums = []
for i in range(1, N + 1):
    if not visited[i]:
        cnt, cand = dfs(i)
        if cnt < K:
            nums.append((cnt, cand))


dp = [0] * K
for i in range(len(nums)):
    # for j in range(K - 1, nums[i][0] - 1, -1):
    for j in range(nums[i][0], K):
        dp[j] = max(dp[j], dp[j - nums[i][0]] + nums[i][1])

print(dp[K - 1])
