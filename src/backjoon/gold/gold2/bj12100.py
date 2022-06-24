import copy
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def move(bo):
    ret = [[0] * N for _ in range(N)]
    b = copy.deepcopy(bo)
    for i in range(N):
        while 0 in b[i]:
            b[i].remove(0)

        j = 0
        while b[i]:
            val = b[i].pop(0)
            if b[i] and b[i][0] == val:
                b[i].pop(0)
                val *= 2
            ret[i][j] = val
            j += 1
    return ret

def rotate(b):
    ret = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            ret[i][j] = b[j][N - i - 1]
    return ret

ans = 0
def dfs(b, d):
    global ans
    if d == 5:
        for i in range(N):
            ans = max(ans, max(b[i]))
        return
    dfs(move(b), d + 1)
    for i in range(3):
        b = rotate(b)
        dfs(move(b), d + 1)
        
dfs(board, 0)
print(ans)