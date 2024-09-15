from bisect import bisect_left, bisect_right
import sys
input = lambda : sys.stdin.readline().rstrip()

ans = 0
M, N, L = map(int, input().split())
shoot = sorted(list(map(int, input().split())))
for _ in range(N):
    x, y = map(int, input().split())
    r = L - y
    if 0 <= r and bisect_right(shoot, x + r) != bisect_left(shoot, x - r):
        ans += 1

print(ans)