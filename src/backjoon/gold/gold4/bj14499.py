import sys
input = lambda : sys.stdin.readline().rstrip()

dy = (0, 0, 0, -1, 1)
dx = (0, 1, -1, 0, 0)
N, M, y, x, K = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(N)]
dice = [0] * 7
di = [(0, 0), (0, 1), (0, -1), (-1, 0), (1, 0)]

def is_vaild(y, x):
    return 0 <= y < N and 0 <= x < M

for dir in list(map(int, input().split())):
    ny = y + dy[dir]
    nx = x + dx[dir]
    if not is_vaild(ny, nx):
        continue

    nd = dice[:]
    if dir == 1:
        nd[1] = dice[4]
        nd[3] = dice[1]
        nd[6] = dice[3]
        nd[4] = dice[6]
    elif dir == 2:
        nd[1] = dice[3]
        nd[3] = dice[6]
        nd[6] = dice[4]
        nd[4] = dice[1]
    elif dir == 3:
        nd[1] = dice[5]
        nd[2] = dice[1]
        nd[6] = dice[2]
        nd[5] = dice[6]
    else:
        nd[1] = dice[2]
        nd[2] = dice[6]
        nd[6] = dice[5]
        nd[5] = dice[1]

    dice = nd[:]
    if b[ny][nx] == 0:
        b[ny][nx] = dice[6]
    else:
        dice[6] = b[ny][nx]
        b[ny][nx] = 0
    y = ny
    x = nx
    print(dice[1])