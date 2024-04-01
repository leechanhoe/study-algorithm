n, k = map(int, input().split())
dp = [[0] * i for i in range(1, n + 1)]

for i in range(n):
    dp[i][0] = 1
    dp[i][-1] = 1
    for j in range(1, len(dp[i])-1):
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]

print(dp[n - 1][k - 1])