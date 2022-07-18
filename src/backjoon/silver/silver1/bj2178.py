from collections import deque
import sys

input = sys.stdin.readline
N, M = map(int, input().split())
board = [input() for _ in range(N)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def is_vaild(y, x):
    return 0 <= x < M and 0 <= y < N

chk = [[False] * M for _ in range(N)]
dq = deque() 
chk[0][0] = True
dq.append((0, 0, 1))
while len(dq):
    y, x, d = dq.popleft()

    if(x == M - 1 and y == N - 1):
        print(d)
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if is_vaild(ny, nx) and not chk[ny][nx] and board[ny][nx] == '1':
            dq.append((ny, nx, d + 1))
            chk[ny][nx] = True