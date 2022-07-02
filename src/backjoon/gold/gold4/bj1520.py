import sys
sys.setrecursionlimit(10 ** 6)
input = lambda : sys.stdin.readline().rstrip()
M, N = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(M)]
chk = [[-1] * N for _ in range(M)]
mv = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def is_vaild(y, x):
    return 0 <= y < M and 0 <= x < N

def dfs(y, x):
    if y == M - 1 and x == N - 1:
        return 1

    if chk[y][x] != -1:
        return chk[y][x]
    chk[y][x] = 0
    for i in range(M):
        print(*chk[i])
    print()
    for dir in mv:
        ny = y + dir[0]
        nx = x + dir[1]
        if is_vaild(ny, nx) and board[y][x] > board[ny][nx]:
            chk[y][x] += dfs(ny, nx)
    return chk[y][x]
print(dfs(0, 0))
for i in range(M):
    print(*chk[i])