import sys

input = lambda: sys.stdin.readline().rstrip()


def get_add(lr, k):  # 어떤 발이 k->lr 발로 갈 때 드는 비용
    if k == 0:
        if lr == 0:
            return 0
        else:
            return 2
    elif k == lr:
        return 1
    elif abs(k - lr) == 1 or abs(k - lr) == 3:
        return 3
    else:
        return 4


INF = int(1e9)
inst = [0] + list(map(int, input().split()))
inst.pop()
N = len(inst)
dp = [[[INF] * 5 for _ in range(5)] for _ in range(N + 1)]
dp[-1][0][0] = 0

for i in range(N):
    for r in range(5):
        for k in range(5):
            add = get_add(inst[i], k)
            dp[i][inst[i]][r] = min(dp[i][inst[i]][r], dp[i - 1][k][r] + add)

    for l in range(5):
        for k in range(5):
            add = get_add(inst[i], k)
            dp[i][l][inst[i]] = min(dp[i][l][inst[i]], dp[i - 1][l][k] + add)

ans = INF
for l in range(5):
    for r in range(5):
        ans = min(ans, dp[N - 1][l][r])

print(ans)
