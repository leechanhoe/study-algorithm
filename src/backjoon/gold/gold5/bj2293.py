N, K = map(int, input().split())
coins = []
for _ in range(N):
    coin = int(input())
    if coin <= K:
        coins.append(coin)

dp = [0] * (K + 1)
for coin in coins:
    dp[coin] += 1
    for i in range(coin, K + 1):
        dp[i] += dp[i - coin]
print(dp[K])