from collections import deque
import sys

input = sys.stdin.readline
R, C = map(int, input().split())
board = [input() for _ in range(R)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def is_vaild(y, x):
    return 0 <= x < C and 0 <= y < R

chk = [[set() for _ in range(C)] for _ in range(R)]

dq = deque() 
chk[0][0] = True
dq.append((0, 0, board[0][0]))
ans = 0
while len(dq):
    y, x, s = dq.popleft()
    ans = max(ans, len(s))
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if is_vaild(ny, nx) and board[ny][nx] not in s:
            ns = s + board[ny][nx]
            if ns not in chk[ny][nx]:
                chk[ny][nx].add(ns)
                dq.append((ny, nx, ns))
print(ans)