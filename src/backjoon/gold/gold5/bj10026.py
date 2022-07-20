import sys
sys.setrecursionlimit(10 ** 6)

N = int(input())
board = []
for _ in range(N):
    board.append(sys.stdin.readline())

def dfs(y, x, board):
    for dir in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        ny = y + dir[0]
        nx = x + dir[1]
        if (0 <= ny < N and 0 <= nx < N) and not chk[ny][nx] and board[ny][nx] == board[y][x]:
            chk[ny][nx] = True
            dfs(ny, nx, board)

ans = 0
chk = [[False] * N for _ in range(N)]
new_board = [[] for _ in range(N)]
for i in range(N):
    for j in range(N):
        new_board[i] += board[i][j] if board[i][j] == 'B' else 'R'
        if not chk[i][j]:
            ans += 1
            dfs(i, j, board)
print(ans, end=" ")
ans = 0
chk = [[False] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if not chk[i][j]:
            ans += 1
            dfs(i, j, new_board)
print(ans, end=" ")