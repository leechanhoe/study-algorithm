N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[[987654321] * 3 for _ in range(M)] for __ in range(N)]

for j in range(M):
    for k in range(3):
        dp[0][j][k] = board[0][j]

for i in range(1, N):
    for j in range(M):
        if j + 1 < M:
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j+1][1] + board[i][j], dp[i-1][j+1][2] + board[i][j])
        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0] + board[i][j], dp[i-1][j][2] + board[i][j])
        if 0 < j:
            dp[i][j][2] = min(dp[i][j][2], dp[i-1][j-1][0] + board[i][j], dp[i-1][j-1][1] + board[i][j])

ans = 987654321
for i in range(M):
    ans = min(ans, min(dp[N-1][i]))
print(ans)