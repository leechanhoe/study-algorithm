import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
item = sorted([int(input()) for _ in range(N)], reverse=True)

ans = 0
for i in range(N):
    if i % 3 != 2:
        ans += item[i]
print(ans)