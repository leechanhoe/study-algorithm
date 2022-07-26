import sys
sys.setrecursionlimit(10 ** 6)
input = lambda : sys.stdin.readline().rstrip()

R, C = map(int, input().split())
board = [input() for _ in range(R)]
chk = [[False] * C for _ in range(R)]
ans = 0

def dfs(y, x):
    if x == C - 1:
        global ans
        ans += 1
        return 1
    for mv in [-1, 0, 1]:
        ny = y + mv
        nx = x + 1
        if 0 <= ny < R and not chk[ny][nx] and board[ny][nx] == '.':
            chk[ny][nx] = True
            if dfs(ny, nx):
                return 1
    return 0

for y in range(R):
    dfs(y, 0)
print(ans)