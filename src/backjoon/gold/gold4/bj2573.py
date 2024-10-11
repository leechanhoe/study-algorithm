# import sys
# from collections import deque

# input = lambda: sys.stdin.readline().rstrip()

# N, M = map(int, input().split())
# board = [list(map(int, input().split())) for _ in range(N)]
# ans = 0


# def bfs(i, j, visited, count):
#     q = deque()
#     visited[i][j] = True
#     q.append((i, j))
#     while q:
#         r, c = q.pop()
#         for dr, dc in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
#             nr = r + dr
#             nc = c + dc
#             if board[nr][nc] and not visited[nr][nc]:
#                 q.appendleft((nr, nc))
#                 visited[nr][nc] = True
#             elif not board[nr][nc]:
#                 count[r][c] += 1


# while 1:

#     cnt = 0
#     visited = [[False] * M for _ in range(N)]
#     count = [[0] * M for _ in range(N)]
#     for i in range(N):
#         for j in range(M):
#             if board[i][j] and not visited[i][j]:
#                 bfs(i, j, visited, count)
#                 cnt += 1
#             if cnt >= 2:
#                 break

#     if cnt == 0:
#         print(0)
#         exit(0)
#     elif cnt >= 2:
#         print(ans)
#         exit(0)

#     for r in range(N):
#         for c in range(M):
#             board[r][c] = max(0, board[r][c] - count[r][c])

#     ans += 1

import collections

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
queue = collections.deque()
day = 0
check = False


def bfs(a, b):
    queue.append((a, b))
    while queue:
        x, y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] != 0 and visited[nx][ny] == False:
                    visited[nx][ny] = True
                    queue.append((nx, ny))
                elif graph[nx][ny] == 0:
                    count[x][y] += 1
    return 1


# 빙산이 분리될때까지 돌아줌
while True:
    visited = [[False] * m for _ in range(n)]
    count = [[0] * m for _ in range(n)]
    result = []
    for i in range(n):
        for j in range(m):
            if graph[i][j] != 0 and visited[i][j] == False:
                result.append(bfs(i, j))
    # 빙산을 깍아줌
    for i in range(n):
        for j in range(m):
            graph[i][j] -= count[i][j]
            if graph[i][j] < 0:
                graph[i][j] = 0

    if len(result) == 0:  # 빙산이 다없어질때까지 분리가 되지않으면 break
        break
    if len(result) >= 2:  # 빙산이 분리되면 break
        check = True
        break
    day += 1

if check:
    print(day)
else:
    print(0)
