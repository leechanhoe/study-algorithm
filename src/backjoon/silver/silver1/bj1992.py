import sys

def div(y, x, n):
    chk = board[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if chk != board[i][j]:
                chk = '-1'
                break
    if chk == '-1':
        print("(", end="")
        n //= 2
        div(y, x, n)
        div(y, x + n, n)
        div(y + n, x, n)
        div(y + n, x + n, n)
        print(")", end="")
    elif chk == '1':
        print(1, end="")
    else:
        print(0, end="")

N = int(input())
board = [sys.stdin.readline() for _ in range(N)]
div(0, 0, N)