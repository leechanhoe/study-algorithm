from collections import deque
import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
board = [input() for _ in range(N)]
INF = 987654321
dist = [[INF] * M for _ in range(N)]
dist[x1-1][y1-1] = 0
move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
dq = deque()
dq.append((x1-1, y1-1))

while dq:
    r, c = dq.pop()
    for dr, dc in move:
        nr = r + dr
        nc = c + dc
        if 0 <= nr < N and 0 <= nc < M and dist[nr][nc] == INF:
            if board[nr][nc] == '0':
                dist[nr][nc] = dist[r][c]
                dq.append((nr, nc))
            else:
                dist[nr][nc] = dist[r][c] + 1
                dq.appendleft((nr, nc))

print(dist[x2-1][y2-1])