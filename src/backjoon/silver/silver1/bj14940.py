from collections import deque

dr = [0, 0, -1, 1]
dc = [1, -1, 0, 0]
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ans = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            dest = (i, j)
        elif board[i][j] == 1:
            ans[i][j] = -1

visited = [[False] * m for _ in range(n)]
visited[dest[0]][dest[1]] = True
q = deque()
q.append((dest[0], dest[1], 1))

while q:
    r, c, dist = q.pop()
    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        if 0 <= nr < n and 0 <= nc < m and not visited[nr][nc] and board[nr][nc] == 1:
            visited[nr][nc] = True
            ans[nr][nc] = dist
            q.appendleft((nr, nc, dist + 1))

for i in range(n):
    print(*ans[i])