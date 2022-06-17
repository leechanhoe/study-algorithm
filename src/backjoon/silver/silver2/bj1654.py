import sys

K, N = map(int, input().split())
a = []
for _ in range(K):
    a.append(int(sys.stdin.readline().rstrip()))

def f(n):
    cnt = 0
    for i in range(K):
        cnt += a[i] // n
    return cnt
le = 1
ri = max(a)
while le <= ri:
    mid = (le + ri) // 2
    if f(mid) >= N:
        le = mid + 1
    else:
        ri = mid - 1
print(ri)