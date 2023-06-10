import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
ans = 0
for i in range(N-1):
    ans += int(input()) - 1

ans += int(input())
print(ans)