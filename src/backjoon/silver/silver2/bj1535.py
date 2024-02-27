N = int(input())
hp = [0] + list(map(int, input().split()))
joy = [0] + list(map(int, input().split()))

dp = [[0] * 101 for _ in range(N + 1)]
for i in range(1, N + 1):
    for j in range(100):
        if j - hp[i] >= 0:
            dp[i][j] = max(dp[i-1][j-hp[i]] + joy[i], dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[N][99])