import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    N = int(input())
    coin = [0] + list(map(int, input().split()))
    M = int(input())
    dp = [0] * (M + 1)
    dp[0] = 1
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            if j >= coin[i]:
                dp[j] += dp[j-coin[i]]

    print(dp[M])