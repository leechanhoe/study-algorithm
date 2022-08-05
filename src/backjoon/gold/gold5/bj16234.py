import sys
from collections import deque
input = lambda : sys.stdin.readline().rstrip()

def bfs(r, c):
    dq = deque()
    dq.append((r, c))
    visit[r][c] = True
    popul = board[r][c]
    uni = [(r, c)]

    while dq:
        y, x = dq.popleft()
        for dir in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ny = y + dir[0]
            nx = x + dir[1]
            if 0 <= ny < N and 0 <= nx < N and not visit[ny][nx] and L <= abs(board[y][x] - board[ny][nx]) <= R:
                visit[ny][nx] = True
                uni.append((ny, nx))
                popul += board[ny][nx]
                dq.append((ny, nx))

    if len(uni) < 2:
        return 0

    mean = popul / len(uni)
    for y, x in uni:
        board[y][x] = int(mean)
    return 1

N, L, R = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

ans = 0
while 1:
    visit = [[False] * N for _ in range(N)]
    mv = 0
    for i in range(N):
        for j in range(N):
            if not visit[i][j]:
                mv += bfs(i, j)
    if not mv:
        break
    ans += 1
print(ans)