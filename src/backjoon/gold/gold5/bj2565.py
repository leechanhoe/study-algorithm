N = int(input())
line = []
for _ in range(N):
    line.append(tuple(map(int, input().split())))
line.sort()
dp = [1] * N
for i in range(1, N):
    for j in range(i):
        if line[j][1] < line[i][1]:
            dp[i] = max(dp[i], dp[j] + 1)
print(N - max(dp))