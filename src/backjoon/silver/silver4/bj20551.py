import bisect
import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
a = [int(input()) for _ in range(N)]
a.sort()

for i in range(M):
    d = int(input())
    le = bisect.bisect_left(a, d)
    if le >= N or d != a[le]:
        print(-1)
    else:
        print(le)