import sys
import bisect
input = lambda : sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    b = sorted(list(map(int, input().split())))

    ans = 0
    for i in a:
        ans += bisect.bisect_left(b, i)
    print(ans)