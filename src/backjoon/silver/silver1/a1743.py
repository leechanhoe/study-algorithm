import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
N, M, K = map(int, input().split())

dx = (0, 0, -1, 1)
dy = (1, -1, 0, 0)

board = [['.'] * M for _ in range(N)]
visit = [[False] * (M + 1) for _ in range(N + 1)]
for _ in range(K):
    y, x = map(int, input().split())
    board[y - 1][x - 1] = '#'

def is_vaild(y, x):
    return 0 <= x < M and 0 <= y < N

ans = 0
cnt = 0
def dfs(y, x):
    global ans, cnt
    visit[y][x] = True
    cnt += 1
    ans = max(cnt, ans)
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if is_vaild(ny, nx) and board[ny][nx] == '#' and not visit[ny][nx]:
            dfs(ny, nx)

for i in range(N):
    for j in range(M):
        if not visit[i][j] and board[i][j] == '#':
            cnt = 0
            dfs(i, j)
print(ans)