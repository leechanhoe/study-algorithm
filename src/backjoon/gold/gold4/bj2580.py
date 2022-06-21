board = [list(map(int, input().split())) for _ in range(9)]
zero = []

def check_row(y, a):
    for j in range(9):
        if a == board[y][j]:
            return False
    return True

def check_col(x, a):
    for i in range(9):
        if a == board[i][x]:
            return False
    return True

def check_rect(y, x, a):
    for i in range(y - (y % 3), y - (y % 3) + 3): # 3x3 검사
        for j in range(x - (x % 3), x - (x % 3) + 3):
            if a == board[i][j]:
                return False
    return True

for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            zero.append((i, j))

def dfs(n):
    if n >= len(zero):
        for i in range(9):
            print(*board[i])
        exit(0)
    y, x = zero[n][0], zero[n][1]

    for num in range(1, 10):
        if check_col(x, num) and check_row(y, num) and check_rect(y, x, num):
            board[y][x] = num
            dfs(n + 1)
            board[y][x] = 0
dfs(0)