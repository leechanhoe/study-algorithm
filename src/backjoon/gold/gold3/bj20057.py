import sys
input = lambda : sys.stdin.readline().rstrip()

dir = [[0, -1], [1, 0], [0, 1], [-1, 0]]
pro = [[[0, 0, 0.02, 0, 0], [0, 0.1, 0.07, 0.01, 0], [0.05, 0, 0, 0, 0], [0, 0.1, 0.07, 0.01, 0], [0, 0, 0.02, 0, 0]]]
pro += [[[0] * 5 for _ in range(5)] for __ in range(3)]
ans = 0

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def rotate():
    for dir in range(1, 4):
        for r in range(5):
            for c in range(5):
                pro[dir][r][c] = pro[dir-1][c][4-r]

def blown(r, c, d):
    global ans, board

    sand = board[r][c]
    for dr in range(-2, 3):
        nr = r + dr
        for dc in range(-2, 3):
            nc = c + dc
            fly = int(sand * pro[d][dr+2][dc+2])
            board[r][c] -= fly
            if 0 <= nr < N and 0 <= nc < N:
                board[nr][nc] += fly
            else:
                ans += fly
    
    nr = r+dir[d][0]
    nc = c+dir[d][1]
    if 0 <= nr < N and 0 <= nc < N:
        board[nr][nc] += board[r][c]
    else:
        ans += board[r][c]
    board[r][c] = 0

rotate()
r = c = N // 2
d = 0
turn = 0
side = 1
for _ in range(250000):
    r += dir[d][0]
    c += dir[d][1]
    # print(r, c)
    blown(r, c, d)

    # for i in board:
    #     print(i)
    # print()

    turn += 1
    if turn == side:
        d = (d + 1) % 4
        if d % 2 == 0:
            side += 1
        turn = 0
    
    if r == 0 and c == 0:
        break

print(ans)