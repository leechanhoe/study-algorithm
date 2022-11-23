from itertools import permutations

def f(a, b, c, cnt):
    global ans
    if a <= 0 and b <= 0 and c <= 0:
        ans = min(ans, cnt)
        return
    
    if a <= 0:
        a = 0
    if b <= 0:
        b = 0
    if c <= 0:
        c = 0

    if dp[a][b][c] <= cnt and dp[a][b][c] != 0:
        return
    
    dp[a][b][c] = cnt

    for damage in permutations([9, 3, 1], 3):
        f(a - damage[0], b - damage[1], c - damage[2], cnt + 1)

N = int(input())
scv = list(map(int, input().split()))
while len(scv) < 3:
    scv += [0]
ans = 61
dp = [[[61] * 61 for _ in range(61)] for __ in range(61)]
f(scv[0], scv[1], scv[2], 0)
print(ans)