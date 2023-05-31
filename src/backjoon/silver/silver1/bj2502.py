D, K = map(int, input().split())

dp1 = [0] * (D + 1)
dp2 = [0] * (D + 1)
dp1[1] = 1
dp2[2] = 1
for i in range(3, D + 1):
    dp1[i] = dp1[i-1] + dp1[i-2]
    dp2[i] = dp2[i-1] + dp2[i-2]

for i in range(1, K + 1):
    tmp = K - dp1[D] * i
    if tmp % dp2[D] == 0:
        print(i)
        print(tmp // dp2[D])
        exit(0)