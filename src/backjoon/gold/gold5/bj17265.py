N = int(input())
board = [list(input().split()) for _ in range(N)]
ma = -987654321
mi = 987654321

def dfs(r, c, val, op):
    global ma, mi
    
    if (r + c) % 2 == 0:
        if op == '+':
            val += int(board[r][c])
        elif op == '-':
            val -= int(board[r][c])
        elif op == '*':
            val *= int(board[r][c])
        if r == N - 1 and c == N - 1:
            ma = max(ma, val)
            mi = min(mi, val)
            return
        
        for nr, nc in [[r + 0, c + 1], [r + 1, c + 0]]:
            if nr < N and nc < N:
                dfs(nr, nc, val, ' ')
    else:
        for nr, nc in [[r + 0, c + 1], [r + 1, c + 0]]:
            if nr < N and nc < N:
                dfs(nr, nc, val, board[r][c])

dfs(0, 0, int(board[0][0]), ' ')
print(ma, mi)