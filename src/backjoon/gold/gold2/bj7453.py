import sys
import bisect

input = lambda : sys.stdin.readline().rstrip()
ans = 0
a, b, c, d = [], [], [], []
N = int(input())
for i in range(N):
    aa, bb, cc, dd = map(int, input().split())
    a.append(aa)
    b.append(bb)
    c.append(cc)
    d.append(dd)

ab = {}
for i in range(N):
    for j in range(N):
        s = a[i] + b[j]
        if s not in ab.keys():
            ab[s] = 1
        else:
            ab[s] += 1

for i in c:
    for j in d:
        s = (i + j) * -1
        if s in ab.keys():
            ans += ab[s]
print(ans)