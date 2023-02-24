import sys
input = lambda : sys.stdin.readline().rstrip()

dir = [[0, 0], [-1, 0], [1, 0], [0, -1], [0, 1]]

N, M, K = map(int, input().split())
board = [[] for _ in range(N)]
pri = [0] + [[] for _ in range(M)]
alive = M

for i in range(N):
    for sha in map(int, input().split()):
        if sha > 0:
            board[i].append([sha, K])
        else:
            board[i].append([sha, 0])

see = [0] + list(map(int, input().split()))

for i in range(1, M+1):
    pri[i].append(0)
    for j in range(4):
        pri[i].append(list(map(int, input().split())))



afterMove = [[[] for _ in range(N)] for __ in range(N)]

def moveSharks():
    for r in range(N):
        for c in range(N):
            if board[r][c][1] == K:
                move = False
                shark = board[r][c][0]
                for d in pri[shark][see[shark]]:
                    nr = r + dir[d][0]
                    nc = c + dir[d][1]
                    if(not(0 <= nr < N and 0 <= nc < N)):
                        continue

                    if(board[nr][nc][1] == 0): # 아무 냄새가 없는 칸
                        afterMove[nr][nc].append(shark)
                        see[shark] = d
                        move = True
                        break
                        
                if move: # 이미 움직였으면
                    continue

                for d in pri[shark][see[shark]]:
                    nr = r + dir[d][0]
                    nc = c + dir[d][1]
                    if(not(0 <= nr < N and 0 <= nc < N)):
                        continue
                    if(board[nr][nc][0] == shark): # 자신의 냄새가 있는 칸
                        afterMove[nr][nc].append(shark)
                        see[shark] = d
                        break

def removeSmell():
    for r in range(N):
        for c in range(N):
            if board[r][c][1] > 0:
                board[r][c][1] -= 1
                if(board[r][c][1] == 0):
                    board[r][c][0] = 0

def kill():
    global alive
    for r in range(N):
        for c in range(N):
            if len(afterMove[r][c]) > 0:
                board[r][c] = [min(afterMove[r][c]), K]
                alive -= len(afterMove[r][c]) - 1

for i in range(1, 1001):
    afterMove = [[[] for _ in range(N)] for __ in range(N)]
    moveSharks()
    removeSmell()
    kill()
    
    if alive == 1:
        print(i)
        exit(0)
        
print(-1)