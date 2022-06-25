import sys

N = int(input())
grape = [0]
for _ in range(N):
    grape.append(int(sys.stdin.readline().rstrip()))
dp = [0]
dp.append(grape[1])
if N > 1:
    dp.append(grape[1] + grape[2])
for i in range(3, N + 1):
    dp.append(max(grape[i] + dp[i-2], grape[i] + grape[i-1] + dp[i-3], dp[i-1]))
print(dp[N])