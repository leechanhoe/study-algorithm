import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))
ans = [0, 0]

def f(y, x, n):
    color = board[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if color != board[i][j]:
                half = n // 2
                f(y, x, half)
                f(y + half, x, half)
                f(y + half, x + half, half)
                f(y, x + half, half)
                return
    ans[color] += 1
    
f(0, 0, N)
print(ans[0])
print(ans[1])