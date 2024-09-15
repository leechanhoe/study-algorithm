from collections import deque

n = int(input())
board = [input() for _ in range(n)]
dist = [[987654321] * n for _ in range(n)]

q = deque()
q.append((0, 0, 0))
dist[0][0] = 0
while q:
    r, c, d = q.pop()
    for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        nr = r + dr
        nc = c + dc
        if 0 <= nr < n and 0 <= nc < n:
            if d < dist[nr][nc] and board[nr][nc] == '1':
                dist[nr][nc] = d
                q.appendleft((nr, nc, d))
            if d + 1 < dist[nr][nc] and board[nr][nc] == '0':
                dist[nr][nc] = d + 1
                q.appendleft((nr, nc, d + 1))

print(dist[n-1][n-1])