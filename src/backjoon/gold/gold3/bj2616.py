N = int(input())
arr = [0] + list(map(int, input().split()))
ma = int(input())

dp = [[0] * (N + 1) for _ in range(4)]

prefix_sum = [0]
for i in range(1, N + 1):
    prefix_sum.append(prefix_sum[i - 1] + arr[i])

for i in range(1, 4):
    for j in range(ma, N + 1):
        dp[i][j] = max(
            dp[i][j - 1], dp[i - 1][j - ma] + prefix_sum[j] - prefix_sum[j - ma]
        )

print(dp[3][N])
