import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
m = []
dp = [[2 ** 31 - 1] * N for _ in range(N)]
for i in range(N):
    m.append(tuple(map(int, input().split())))
    dp[i][i] = 0                           # ABCD연속행렬 곱의 최솟값 =
                                           # min(ABCD ,
for k in range(1, N): # 크기               # min(A) + min(BCD) + 합치는 비용(A행 * A열 * D열),
    for i in range(N - k): # 시작점        # min(AB) + min(CD) + 합치는 비용(A행 * B열 * D열),
        for j in range(k): # k안에서 2분할 # min(ABC) + min(D) + 합치는 비용(A행 * C열 * D열))
            dp[i][i+k] = min(dp[i][i+k], dp[i][i+j] + dp[i+j+1][i+k] + m[i][0] * m[i+j+1][0] * m[i+k][1])
print(dp[0][N-1])