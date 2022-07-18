from collections import deque
import sys

input = sys.stdin.readline

dy = (-1, -2, -2, -1, 1, 2, 2, 1)
dx = (-2, -1, 1, 2, 2, 1, -1, -2)

for _ in range(int(input())):
    I = int(input())
    curY, curX = map(int, input().split())
    goalY, goalX = map(int, input().split())

    def is_vaild(y, x):
        return 0 <= x < I and 0 <= y < I

    chk = [[False] * I for _ in range(I)]
    dq = deque() 
    chk[curY][curX] = True
    dq.append((curY, curX, 0))
    while len(dq):
        y, x, d = dq.popleft()

        if(y == goalY and x == goalX):
            print(d)
            break

        for i in range(8):
            ny = y + dy[i]
            nx = x + dx[i]

            if is_vaild(ny, nx) and not chk[ny][nx]:
                dq.append((ny, nx, d + 1))
                chk[ny][nx] = True