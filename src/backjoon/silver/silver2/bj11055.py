N = int(input())
nums = list(map(int, input().split()))
dp = nums.copy()

for i in range(1, N):
    for j in range(i):
        if nums[j] < nums[i]:
            dp[i] = max(dp[j] + nums[i], dp[i])
print(max(dp))