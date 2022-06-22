from collections import deque

dy = (0, 1, 0, -1)
dx = (1, 0, -1, 0)

N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
sry = srx = sby = sbx = -1

for i in range(N):
    for j in range(M):
        if board[i][j] == 'R':
            sry, srx = i, j
        if board[i][j] == 'B':
            sby, sbx = i, j

def go_next(ry, rx, by, bx, k):
    nry, nrx, nby, nbx = ry, rx, by, bx

    while 1:
        nry += dy[k]
        nrx += dx[k]
        if board[nry][nrx] == 'O':
            nry, nrx = -1, -1
            break
        elif board[nry][nrx] == '#':
            nry -= dy[k]
            nrx -= dx[k]
            break

    while 1:
        nby += dy[k]
        nbx += dx[k]
        if board[nby][nbx] == 'O':
            nby, nbx = -1, -1
            break
        elif board[nby][nbx] == '#':
            nby -= dy[k]
            nbx -= dx[k]
            break
    
    if nry != -1 and nry == nby and nrx == nbx:
        if k == 0:
            if rx < bx:
                nrx -= 1
            else:
                nbx -= 1
        elif k == 1:
            if ry < by:
                nry -= 1
            else:
                nby -= 1
        elif k == 2:
            if bx < rx:
                nrx += 1
            else:
                nbx += 1
        else:
            if by < ry:
                nry += 1
            else:
                nby += 1
    return nry, nrx, nby, nbx

def bfs():
    chk = set()
    dq = deque()
    chk.add((sry, srx, sby, sbx))
    dq.append((sry, srx, sby, sbx, 0))

    while dq:
        ry, rx, by, bx, d = dq.popleft()
        if by == -1 and bx == -1:
            continue
        
        if ry == -1 and rx == -1:
            return d
        
        if d < 10:
            nd = d + 1
            for k in range(4):
                nry, nrx, nby, nbx = go_next(ry, rx, by, bx, k)
                if (nry, nrx, nby, nbx) not in chk:
                    chk.add((nry, nrx, nby, nbx))
                    dq.append((nry, nrx, nby, nbx, nd))
    return -1
print(bfs())
        
# N, M = map(int, input().split())
# b = []
# red = []
# blue = []
# dirs = [(0, 0), (1, 0), (0, -1), (0, 1), (-1, 0)]
# chk = [[[[[False] * 5 for _ in range(M)] for _ in range(N)] for _ in range(M)] for _ in range(N)]
# for i in range(N):
#     b.append(input())
#     if 'R' in b[-1]:
#         red = [i, b[-1].index('R')]
#     if 'B' in b[-1]:
#         blue = [i, b[-1].index('B')]

# def is_blank(dir, y, x):
#     if b[y + dir[0]][x + dir[1]] != '#':
#         return True
#     return False

# def move(dir, y, x, y2, x2):
#     ch = b[y+dir[0]][x+dir[1]]
#     if ch == "#":
#         return(y, x)

#     overrap = False
#     while ch == '.' or ch == 'B' or ch == 'R': # 움직임
#         y += dir[0]
#         x += dir[1]
#         if y == y2 and x == x2: # 겹쳤을때 플래그세움
#             overrap = True
#         ch = b[y][x]

#     if ch == 'O': # 구멍일때
#         return (-1, -1)
#     elif ch == '#': # 벽일때
#         y -= dir[0]
#         x -= dir[1]
#         if overrap: # 겹쳤을때
#             y -= dir[0]
#             x -= dir[1]
#     return (y, x)

# cnt = 1
# dq = deque()
# dq.append((red[0], red[1], blue[0], blue[1], cnt))
# while dq:
#     ry, rx, by, bx, cnt = dq.popleft()
#     if cnt > 10:
#         cnt = -1
#         break
#     for i in range(1, 5): # 1.up 2.left 3.right 4.down
#         if (is_blank(dirs[i], ry, rx) and not chk[ry][rx][by][bx][i]): # 왔던 방향에 체크되있음
#             nry, nrx = move(dirs[i], ry, rx, by, bx) # 빨간 구슬 움직임
#             nby, nbx = move(dirs[i], by, bx, ry, rx)
#             print("red", nry, nrx, "blue", nby, nbx)
#             if nry == -1: # 빨간구슬이 나왔을 때
#                 if nby == -1: # 파란구슬도 나왔을 때
#                     cnt = -1
#                 dq.clear()
#                 break            
#             dq.append((nry, nrx, nby, nbx, cnt + 1))
#             chk[nry][nrx][nby][nbx][-i] = True
# print(cnt)