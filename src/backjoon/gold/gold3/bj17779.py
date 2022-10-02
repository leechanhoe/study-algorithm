import sys
input = sys.stdin.readline

N = int(input())
board = [[*map(int, input().split())] for _ in range(N)]

def divide(x, y, d1, d2):
    popul = [0] * 5
    is5 = [[False] * N for _ in range(N)]

    d1_ = d2_ = d = 0
    for r in range(x, x + d1 + d2 + 1):
        for c in range(y - d1_, y + d2_ + 1):
            is5[r][c] = True

        if d < d1:
            d1_ += 1
        else:
            d1_ -= 1

        if d < d2:
            d2_ += 1
        else:
            d2_ -= 1
        d += 1

    for r in range(N):
        for c in range(N):
            if is5[r][c]:
                popul[4] += board[r][c]
            else:
                if r < x + d1 and c <= y:
                    popul[0] += board[r][c]
                elif r <= x + d2 and y < c:
                    popul[1] += board[r][c]
                elif x + d1 <= r and c < y - d1 + d2:
                    popul[2] += board[r][c]
                elif x + d2 < r and y - d1 + d2 <= c:
                    popul[3] += board[r][c]

    return max(popul) - min(popul)

ans = 987654321
for x in range(N):
    for y in range(N):
        for d1 in range(1, N):
            for d2 in range(1, N):
                if (x + d1 + d2 < N) and (y - d1 >= 0) and (y + d2 < N):
                    ans = min(ans, divide(x, y, d1, d2))
print(ans)