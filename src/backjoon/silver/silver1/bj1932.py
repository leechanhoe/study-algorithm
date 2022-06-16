import sys
imput = lambda : sys.stdin.readline().rstrip()

N = int(input())
dp = [list(map(int, input().split())) for _ in range(N)]

for i in range(1, N):
    for j in range(len(dp[i])):
        if j == 0:
            dp[i][j] += dp[i - 1][j]
        elif j == len(dp[i]) - 1:
            dp[i][j] += dp[i - 1][j - 1]
        else:
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1])
print(max(dp[N - 1]))