import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)

N, Q = map(int, input().split())
N2 = 2 ** N
ice = [list(map(int, input().split())) for _ in range(2 ** N)]

def rotate(r, c, l):
    tmp = [[0] * l for _ in range(l)]

    for i in range(l):
        for j in range(l):
            tmp[i][j] = ice[r+(l-j-1)][c+i]
    for i in range(l):
        for j in range(l):
            ice[r+i][c+j] = tmp[i][j]

def move(l):
    for i in range(0, N2, l):
        for j in range(0, N2, l):
            rotate(i, j, l)

def melt():
    loc = []
    for r in range(N2):
        for c in range(N2):
            cnt = 0
            for dr, dc in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < N2 and 0 <= nc < N2 and 0 < ice[nr][nc]:
                    cnt += 1
            if 0 < ice[r][c] and cnt < 3:
                loc.append((r, c))
    
    for r, c in loc:
        ice[r][c] -= 1

def dfs(r, c):
    cnt = 0
    for dr, dc in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
        nr = r + dr
        nc = c + dc
        if 0 <= nr < N2 and 0 <= nc < N2 and 0 < ice[nr][nc] and not visit[nr][nc]:
            visit[nr][nc] = True
            cnt += 1
            cnt += dfs(nr, nc)

    return cnt
            
for L in map(int, input().split()):
    move(2 ** L)
    melt()
    # for i in range(N2):
    #     print(ice[i])

visit = [[False] * N2 for _ in range(N2)]
ma = 0
for r in range(N2):
    for c in range(N2):
        if not visit[r][c]:
            ma = max(ma, dfs(r, c))

su = sum(map(sum, ice))
print(su)
print(ma)
