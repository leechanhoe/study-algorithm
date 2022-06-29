from collections import deque
from sys import stdin

M, N = map(int, input().split())
board = []
mv = [(0, 1), (0, -1), (-1, 0), (1, 0)]
ans = 0
dq = deque()
for i in range(N):
    board.append(list(map(int, stdin.readline().rstrip().split())))
    for j in range(M):
        if board[i][j] == 1:
            dq.append((i, j, 0))

def is_vaild(y, x):
    return 0 <= y < N and 0 <= x < M

while dq:
    y, x, d = dq.popleft()
    ans = max(ans, d)
    for dir in mv:
        ny = y + dir[0]
        nx = x + dir[1]
        if is_vaild(ny, nx) and board[ny][nx] == 0:
            dq.append((ny, nx, d+1))
            board[ny][nx] = 1

for i in range(N):
    if 0 in board[i]:
        ans = -1
        break
print(ans)