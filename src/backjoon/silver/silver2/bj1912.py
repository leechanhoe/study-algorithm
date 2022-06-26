N = int(input())
nums = [-987654321] + list(map(int, input().split()))
dp = [-987654321] * (N + 1)
s = dp[0] = nums[0]
for i in range(1, N + 1):
    dp[i] =  nums[i] + dp[i-1] if dp[i-1] > 0 else nums[i]
print(max(dp))