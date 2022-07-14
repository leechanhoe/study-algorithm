N = int(input())
dp = [[i] for i in range(N + 1)]
for i in range(2, N + 1):
    temp = []
    if i % 3 == 0 and i % 2 == 0:
        if len(dp[i // 3]) > len(dp[i // 2]):
            temp = dp[i // 2]
        else:
            temp = dp[i // 3]
    elif i % 3 == 0:
        temp = dp[i // 3]
    elif i % 2 == 0:
        temp = dp[i // 2]
    else:
        temp = dp[i - 1]
    if len(temp) > len(dp[i - 1]):
        temp = dp[i - 1]
    dp[i] += temp
print(len(dp[N]) - 1)
print(*dp[N])