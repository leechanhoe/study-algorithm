import sys
from copy import deepcopy
input = sys.stdin.readline

def spread(board):
    nboard = deepcopy(board)
    for y in range(R):
        for x in range(C):
            if board[y][x] >= 5:
                dirt = board[y][x] // 5
                for dir in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    ny = y + dir[0]
                    nx = x + dir[1]
                    if 0 <= ny < R and 0 <= nx < C and board[ny][nx] >= 0:
                        nboard[ny][nx] += dirt
                        nboard[y][x] -= dirt
    return nboard

def clean(board):
    nboard = deepcopy(board)
    for i in range(C):
        if 2 <= i:
            nboard[cleaner[0]][i] = board[cleaner[0]][i-1]
            nboard[cleaner[1]][i] = board[cleaner[1]][i-1]
        if i < C - 1:
            nboard[0][i] = board[0][i+1]
            nboard[R-1][i] = board[R-1][i+1]
    for i in range(R):
        if i < cleaner[0]:
            if 1 <= i:
                nboard[i][0] = board[i-1][0]
            nboard[i][C-1] = board[i+1][C-1]
        elif i > cleaner[1]:
            if i < R - 1:
                nboard[i][0] = board[i+1][0]
            nboard[i][C-1] = board[i-1][C-1]

    nboard[cleaner[0]][1] = 0
    nboard[cleaner[1]][1] = 0
    return nboard

R, C, T = map(int, input().split())
board = []
cleaner = []
for i in range(R):
    board.append(list(map(int, input().split())))
    if board[i][0] == -1:
        cleaner.append(i)

for t in range(T):
    board = spread(board)
    board = clean(board)

ans = 2
for i in range(R):
    ans += sum(board[i])
print(ans)