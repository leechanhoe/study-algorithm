import sys

input = lambda: sys.stdin.readline().rstrip()

C, N = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(N)]
INF = 987654321
dp = [INF] * (C + 100)
dp[0] = 0

for cost, num in city:
    for i in range(num, C + 100):
        dp[i] = min(dp[i], dp[i - num] + cost)

print(min(dp[C:]))
