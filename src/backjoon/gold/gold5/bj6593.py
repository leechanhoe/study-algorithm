from collections import deque
import sys

input = sys.stdin.readline
move = [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]

def is_valid_loc(z, y, x): # 유효 위치 검사
    return 0 <= z < L and 0 <= y < R and 0 <= x < C 

while 1:
    L, R, C = map(int, input().strip().split())
    if not L:
        break

    b = [[] for _ in range(L)] # 빌딩을 3차원 배열로 입력받음
    visited = [[[False] * C for _ in range(R)] for __ in range(L)]
    start = end = (-1, -1, -1, 0)
    for i in range(L):
        for j in range(R):
            b[i].append(input().strip())
            if 'S' in b[i][j]:
                start = (i, j, b[i][j].find('S'), 0)
            elif 'E' in b[i][j]:
                end = (i, j, b[i][j].find('E'), 0)
        input().strip()

    dq = deque()
    dq.append(start)
    visited[start[0]][start[1]][start[2]] = True
    escaped = False
    while dq:
        z, y, x, t = dq.popleft()
        if z == end[0] and y == end[1] and x == end[2]:
            print(f"Escaped in {t} minute(s).")
            escaped = True
            break

        for dir in move:
            nz = z + dir[0]
            ny = y + dir[1]
            nx = x + dir[2]
            if is_valid_loc(nz, ny, nx) and (b[nz][ny][nx] == '.' or b[nz][ny][nx] == 'E') and not visited[nz][ny][nx]:
                visited[nz][ny][nx] = True
                dq.append((nz, ny, nx, t + 1))
                
    if not escaped:
        print("Trapped!")