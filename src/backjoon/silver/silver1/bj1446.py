N, D = map(int, input().split())
cut = [[] for _ in range(20010)]
dp = [0] * 20010
for i in range(N):
    s, e, d = map(int, input().split())
    cut[e].append((s, d))

for i in range(D + 1):
    if 0 < i:
        dp[i] = dp[i-1] + 1
    for s, d in cut[i]:
        dp[i] = min(dp[i], dp[s] + d)

print(dp[D])