import sys
from collections import deque
input = lambda : sys.stdin.readline().rstrip()

def eat(): # 물고기 먹기
    shark[3] += 1
    if shark[3] == shark[2]:
        shark[2] += 1
        shark[3] = 0

def bfs(y, x):
    dq = deque()
    chk = [[False] * N for _ in range(N)]
    chk[y][x] = True
    dq.append((y, x, 0))
    mv = [(-1, 0), (0, -1), (1, 0), (0, 1)]

    catch_time = 987654321
    fishes = []
    while dq:
        y, x, t = dq.popleft()
        if catch_time < t + 1: # 최초로 잡은 시간까지는 가능한 물고기 모두 탐색
            continue
        for dir in mv:
            ny = y + dir[0]
            nx = x + dir[1]
            if (0 <= ny < N and 0 <= nx < N) and not chk[ny][nx] and board[ny][nx] <= shark[2]:
                chk[ny][nx] = True
                if board[ny][nx] and board[ny][nx] < shark[2]: # 물고기가 작으면 
                    fishes.append((ny, nx))
                    catch_time = t + 1
                    continue
                dq.append((ny, nx, t + 1))

    if fishes:
        fishes.sort()
        shark[0], shark[1] = fishes[0][0], fishes[0][1]
        board[fishes[0][0]][fishes[0][1]] = 0  # 잡은 물고기 중에서 우선순위 따져 고르기
        eat()
        return catch_time # 이동시간 반환

    return 0

N = int(input())
board = []
for i in range(N):
    board.append(list(map(int, input().split())))
    if 9 in board[-1]:
        shark = [i, board[i].index(9), 2, 0] # [y, x, 크기, 현재 크기에서 먹은 물고기 수]

board[shark[0]][shark[1]] = 0
ans = 0
while 1:
    time = bfs(shark[0], shark[1])
    if time:
        ans += time
    else:
        break
print(ans)