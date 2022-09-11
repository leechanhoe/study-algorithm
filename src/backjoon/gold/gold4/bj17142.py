import sys
from collections import deque
from itertools import combinations
from copy import deepcopy
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
birus = []

def bfs(board, active, birus):
    visit = [[False] * N for _ in range(N)]
    dq = deque(active)

    while dq:
        y, x, t = dq.popleft()
        visit[y][x] = True
        for dir in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
            ny = y + dir[0]
            nx = x + dir[1]
            nt = t + 1
            if 0 <= ny < N and 0 <= nx < N and not visit[ny][nx] and not board[ny][nx] == 1:
                visit[ny][nx] = True
                board[ny][nx] = nt
                dq.append([ny, nx, nt])

    for y, x, t in birus:
        board[y][x] = -1

    ret = 2
    for i in range(N):
        if 0 in board[i]:
            return -1
        ret = max(ret, max(board[i])) 
    return ret - 2

for i in range(N):
    board.append(list(map(int, input().split())))
    for j in range(N):
        if(board[i][j] == 2):
            birus.append([i, j, 2])

ans = 987654321
for com in combinations(birus, M):
    nboard = deepcopy(board)
    time = bfs(nboard, com, birus)
    if time >= 0:
        ans = min(ans, time)
print(ans if ans < 987654321 else -1)