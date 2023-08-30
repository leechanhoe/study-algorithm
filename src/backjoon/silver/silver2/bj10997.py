N = int(input())

if N == 1:
    print('*')
    exit(0)

board = [[' '] * ((N - 1) * 4 + 1) for _ in range((N - 1) * 4 + 3)]

def f(n, r, c):
    global board
    if n == 1:
        board[r][c] = '*'
        board[r+1][c] = '*'
        board[r+2][c] = '*'
        return

    w = (n - 1) * 4 + 1
    h = (n - 1) * 4 + 3
    for i in range(c, c + w):
        board[r][i] = '*'
        board[r+h-1][i] = '*'
    
    for i in range(r, r + h):
        board[i][c] = '*'
        board[i][c+w-1] = '*'

    board[r+1][c+w-1] = ' '
    board[r+2][c+w-2] = '*'

    f(n - 1, r + 2, c + 2)

f(N, 0, 0)
for row in board:
    print(''.join(row).strip())