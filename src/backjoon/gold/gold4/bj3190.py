from collections import deque
import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
board = [[0] * (N + 1) for _ in range(N + 1)]
move = [(0, 1), (1, 0), (0, -1), (-1, 0)] # 우 하 좌 상 -> +1하면 90도 오른쪽으로
for _ in range(int(input())):
    ay, ax = map(int, input().split())
    board[ay][ax] = 1 # 사과가 있는 칸은 1
dirs = []
for _ in range(int(input())):
    dirs.append(tuple(input().split()))

dq = deque()
dq.append((1, 1))
dir = 0
t = 0
while 1:
    t += 1
    y, x = dq[-1]
    y += move[dir][0]
    x += move[dir][1]
    if not (0 < y <= N and 0 < x <= N) or (y, x) in dq: # 나가거나 자기몸에 닿을때
        break

    if board[y][x] == 0:
        dq.popleft()
    else:
        board[y][x] = 0
    
    dq.append((y, x))
    if dirs and t == int(dirs[0][0]):
        if dirs[0][1] == 'D':
            dir = (dir + 1) % 4
        else:
            dir = (dir + 3) % 4
        dirs.pop(0)
print(t)