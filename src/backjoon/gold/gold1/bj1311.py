import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
d = [list(map(int, input().split())) for _ in range(N)]
dp = [987654321] * (1 << N) # 현재까지의 상태에 따른 최소 비용을 저장
dp[0] = 0

for i in range(1 << N):
    k = 0
    for j in range(N):
        if i & (1 << j): # i상태에 할당된 일의 개수 세기
            k += 1

    for j in range(N):
        # j번 일이 할당되지 않았고, i 상태에서 j번 일을 할당하는 것이 비용이 더 낮다면
        if i & (1 << j) == 0 and dp[i|(1<<j)] > dp[i] + d[k][j]:
            # 현재의 최소 비용(dp[i])에 해당 일을 처리하는 비용(d[k][j])을 더한다
            dp[i|(1<<j)] = dp[i] + d[k][j]

    print(i, dp)
print(dp[-1])