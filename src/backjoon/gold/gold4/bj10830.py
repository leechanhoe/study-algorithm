import sys
input = sys.stdin.readline

N, B = map(int, input().split())
A = [[*map(int, input().split())] for _ in range(N)]

def mul(a, b):
    ret = [[0] * N for _ in range(N)]

    for row in range(N):
        for col in range(N):
            e = 0
            for i in range(N):
                e += a[row][i] * b[i][col]
            ret[row][col] = e % 1000 
    return ret

def square(a, b):
    if b == 1:
        for x in range(len(A)):
            for y in range(len(A)):
                a[x][y] %= 1000
        return a

    tmp = square(a, b//2)
    if b % 2:
        return mul(mul(tmp, tmp), a)
    else:
        return mul(tmp, tmp)

for s in square(A, B):
    print(*s)