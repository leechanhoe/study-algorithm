import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
dir = [(-1, 0), (0, 1), (1, 0), (0, -1)] # dir의 인덱스를 -1 하면 왼쪽
robot = list(map(int, input().split()))

board = [] # 0이면 청소를 안한곳 1이면 벽 2면 청소가 된 곳
for i in range(N):
    board.append(list(map(int, input().split())))
board[robot[0]][robot[1]] = 2

ans = 1
while 1:
    y, x, d = robot
    moved = False

    for i in range(d - 1, d - 5, -1): # 왼쪽부터 탐색하여
        ny = y + dir[i][0]
        nx = x + dir[i][1]
        if (0 <= ny < N and 0 <= nx < M) and board[ny][nx] == 0: # 청소 안한 곳을 찾으면
            robot[0], robot[1] = ny, nx
            robot[2] = i % 4 # 현재 방향
            board[ny][nx] = 2
            ans += 1
            moved = True
            break

    if not moved: # 움직이지 못했으면
        if board[y + dir[d-2][0]][x + dir[d-2][1]] == 1: # 뒤쪽이 벽일경우
            break
        else: # 벽이 아니면 뒤로 이동
            robot[0] = y + dir[d-2][0] 
            robot[1] = x + dir[d-2][1]
print(ans)