import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
M = int(input())
light = [*map(int, input().split())]
ans = max(light[0], N - light[-1])
for i in range(1, M):
    diff = light[i] - light[i-1]
    ans = max(ans, diff // 2 + (1 if diff % 2 else 0))
print(ans)