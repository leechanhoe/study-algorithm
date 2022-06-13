import sys
input = sys.stdin.readline
N, M = map(int, input().strip().split())
a = {input().strip() for _ in range(N)}
b = {input().strip() for _ in range(M)}
ans = list(a.intersection(b))

print(len(ans))
for i in sorted(ans):
    print(i)