N = int(input())
consult = []
for _ in range(N):
    consult.append(list(map(int, input().split())))

dp = [0] * (N + 1)
for i in range(N - 1, -1, -1):
    day = i + consult[i][0]
    if day > N:
        dp[i] = dp[i + 1]
    else:
        dp[i] = max(dp[i + 1], dp[day] + consult[i][1])

print(dp[0])