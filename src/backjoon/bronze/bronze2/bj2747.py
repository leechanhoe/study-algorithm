dp = [0,1]
for i in range(2, 46):
    dp.append(dp[-1] + dp[-2])
print(dp[int(input())])