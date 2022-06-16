N = int(input())
a = list(map(int, input().split()))
dp = [1] * N
for i in range(N):
    for j in range(i):
        if a[j] < a[i]:
            dp[i] = max(dp[j] + 1, dp[i])
print(max(dp))