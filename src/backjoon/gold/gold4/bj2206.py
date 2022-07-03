import sys
from collections import deque
input = lambda : sys.stdin.readline().rstrip()
N, M = map(int, input().split())
board = [input() for _ in range(N)]
chk = [[[False] * 2 for _ in range(M)] for _ in range(N)] # [y][x][broken?]
mv = [(0, 1), (0, -1), (1, 0), (-1, 0)]

dq = deque()
dq.append((0, 0, 1, 0)) # 맨 오른쪽은 벽을 부순상태인지 기록
chk[0][0][0] = True
ans = 0
while dq:
    y, x, d, broken = dq.popleft()
    if y == N - 1 and x == M - 1:
        ans = d
        break
    
    for dir in mv:
        ny = y + dir[0]
        nx = x + dir[1]
        if 0 <= ny < N and 0 <= nx < M:
            if board[ny][nx] == '0' and not chk[ny][nx][broken]:
                chk[ny][nx][broken] = True
                dq.append((ny, nx, d + 1, broken))
            elif board[ny][nx] == '1' and not chk[ny][nx][broken] and not broken: # 벽을 부수지 않은 상태에서 1을 만났을 때
                chk[ny][nx][broken] = True
                dq.append((ny, nx, d + 1, 1))
if not ans:
    ans = -1
print(ans)