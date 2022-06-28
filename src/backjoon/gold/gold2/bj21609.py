N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
mv = ((-1, 0), (0, -1), (1, 0), (0, 1))
chk = [[False] * N for _ in range(N)]

def is_vaild(y, x):
    return 0 <= y < N and 0 <= x < N

def dfs(y, x, n, blocks, rb, chk0):
    chk0[y][x] = True
    blocks.append((y, x))
    if board[y][x] == 0:
        rb += 1
    for m in mv:
        ny = y + m[0]
        nx = x + m[1]
        if is_vaild(ny, nx) and not chk0[ny][nx] and (board[ny][nx] == n or board[ny][nx] == 0):
            if board[ny][nx] != 0:
                chk[ny][nx] = True
            blocks, rb = dfs(ny, nx, n, blocks, rb, chk0)
    return blocks, rb

score = 0
def pop_block():
    global chk
    std = [[0] * N for _ in range(N)]
    max_len = 0
    rainbow = [[0] * N for _ in range(N)]
    index = 0 # 지워야할 기준 블록의 인덱스
    for i in range(N):
        for j in range(N):
            if not chk[i][j] and board[i][j] > 0:
                chk0 = [[False] * N for _ in range(N)]
                std[i][j], rainbow[i][j] = dfs(i, j, board[i][j], list(), 0, chk0)
                if max_len <= len(std[i][j]):
                    if max_len == len(std[i][j]):
                        if rainbow[index[0]][index[1]] <= rainbow[i][j]: # 블록 개수가 같으면 무지개블럭 검사
                            index = (i, j)
                    else:
                        max_len = len(std[i][j])
                        index = (i, j)
    chk = [[False] * N for _ in range(N)]

    if max_len < 2: # 블록 그룹이 없으면
        return 0

    for i, j in std[index[0]][index[1]]:
        board[i][j] = -2 # 빈공간을 -2 로
    global score
    score += len(std[index[0]][index[1]]) ** 2
    return 1

def gravity():
    for i in range(N - 2, -1, -1):
        for j in range(N):
            if board[i][j] < 0:
                continue
            for k in range(i, N - 1):
                if board[k][j] == -1:
                    break
                if board[k+1][j] == -2:
                    board[k][j], board[k+1][j] = board[k+1][j], board[k][j]

def rotate():
    ret = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            ret[i][j] = board[j][N-i-1]
    return ret

while pop_block():
    gravity()
    board = rotate()
    gravity()
print(score)