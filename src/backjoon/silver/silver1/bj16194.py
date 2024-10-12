N = int(input())
p = [0] + list(map(int, input().split()))
INF = 1e9
dp = [INF] * (N + 1)
dp[0] = 0
for i in range(1, N + 1):
    for j in range(i + 1):
        dp[i] = min(dp[i], dp[i - j] + p[j])

print(dp[N])
