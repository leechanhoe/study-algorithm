N = int(input())
dp = [0] * N
for i in range(N):
    x = float(input())
    if i:
        dp[i] = max(x, dp[i - 1] * x)
    else:
        dp[i] = x

print("{:.3f}".format(max(dp)))
