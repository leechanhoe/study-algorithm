N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[0] * N for _ in range(N)]
dp[0][0] = 1
for i in range(N):
    for j in range(N):
        k = board[i][j]

        if k == 0 or dp[i][j] == 0:
            continue
        if i + k < N:
            dp[i + k][j] += dp[i][j]
        if j + k < N:
            dp[i][j + k] += dp[i][j]

print(dp[-1][-1])
