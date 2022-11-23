import sys
from collections import deque
input = lambda : sys.stdin.readline().rstrip()

M, N = map(int, input().split())
maze = [list(map(int, list(input()))) for _ in range(N)]
dist = [[-1] * M for _ in range(N)]

q = deque()
q.append((0, 0))
dist[0][0] = 0
while q:
    y, x = q.popleft() 
    for dir in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
        ny = y + dir[0]
        nx = x + dir[1]
        if 0 <= ny < N and 0 <= nx < M and dist[ny][nx] == -1:
            if maze[ny][nx] == 0:
                dist[ny][nx] = dist[y][x]
                q.appendleft((ny, nx))
            else:
                dist[ny][nx] = dist[y][x] + 1
                q.append((ny, nx))

print(dist[N-1][M-1])
