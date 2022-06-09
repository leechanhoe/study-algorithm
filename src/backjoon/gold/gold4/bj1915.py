n, m = map(int, input().split())
board = [input() for _ in range(n)]
dp = [[0] * m for _ in range(n)]
ans = 0

for i in range(n):
    for j in range(m):
        if i == 0 or (i > 0 and j == 0):
            dp[i][j] = int(board[i][j])
        else:
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1 if board[i][j] == '1' else 0
        ans = max(dp[i][j], ans)

print(ans * ans)