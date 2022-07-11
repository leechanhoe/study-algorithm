import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
board = [[*map(int, input().split())] for _ in range(N)]
move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
visit = [[False] * M for _ in range(N)]

def dfs(y, x, i, total):
    global ans
    # if ans >= total + ma * (3 - i): # 현재 합에 종이에서 제일 큰수를 더한것이 현재 구한 답보다 작으면 
    #     return # 탐색할 필요가 없으므로 백트래킹
    if i == 3:
        ans = max(ans, total)
        return
    else:
        for dir in move:
            ny = y + dir[0]
            nx = x + dir[1]
            if 0 <= ny < N and 0 <= nx < M and not visit[ny][nx]:
                visit[ny][nx] = True
                if i == 1: # ㅗ 모양은 제자리에서 3방향 탐색
                    dfs(y, x, i + 1, total + board[ny][nx])
                dfs(ny, nx, i + 1, total + board[ny][nx])
                visit[ny][nx]= False

ans = 0
ma = max(map(max, board))
for y in range(N):
    for x in range(M):
        visit[y][x] = True
        dfs(y, x, 0, board[y][x])
        visit[y][x] = False
print(ans)