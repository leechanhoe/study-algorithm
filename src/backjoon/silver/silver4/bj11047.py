N, K = map(int, input().split())
coins = [int(input()) for _ in range(N)]
cnt = 0
for coin in reversed(coins):
    c = K // coin
    K -= c * coin
    cnt += c
print(cnt)