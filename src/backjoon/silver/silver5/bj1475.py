N = input()

dp = [0] * 10
for ch in N:
    dp[int(ch)] += 1
n69 = dp[6] + dp[9]
dp[6] = n69 // 2 if n69 % 2 == 0 else n69 // 2 + 1
dp[9] = 0
print(max(dp))