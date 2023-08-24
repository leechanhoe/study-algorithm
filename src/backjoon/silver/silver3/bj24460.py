import sys
imput = lambda : sys.stdin.readline().rstrip()

N = int(input())
chair = [list(map(int, input().split())) for _ in range(N)]

def dq(n, r, c):
    if n == 1:
        return chair[r][c]
    
    half = n // 2
    c = [dq(half, r, c), dq(half, r, c + half), dq(half, r + half, c), dq(half, r + half, c + half)]
    c.sort()
    return c[1]

print(dq(N, 0, 0))