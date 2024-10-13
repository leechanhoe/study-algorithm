import sys

input = lambda: sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**7)

N = int(input())
adj = [[] for _ in range(N + 1)]
dp = [[0, 0] for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

visited = [False] * (N + 1)


def dfs(start):
    global visited, adj, dp

    visited[start] = True
    if not adj[start]:
        dp[start][1] = 1
        dp[start][0] = 0
    else:
        for next in adj[start]:
            if not visited[next]:
                dfs(next)
                dp[start][1] += min(dp[next][0], dp[next][1])
                dp[start][0] += dp[next][1]

        dp[start][1] += 1


dfs(1)
print(min(dp[1][0], dp[1][1]))
