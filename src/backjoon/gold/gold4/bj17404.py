import sys
import copy
input = lambda : sys.stdin.readline().rstrip()
INF = 1987654321

N = int(input())
rgb = []
for _ in range(N):
    rgb.append([*map(int, input().split())])

ans = INF
for i in range(3): # 1번째 집 rgb 선택
    dp = copy.deepcopy(rgb)
    for j in range(3): 
        if i != j: # 선택한 rgb 이외는 무한으로 초기화
            dp[0][j] = INF

    for j in range(1, N):
        dp[j][0] += min(dp[j-1][1], dp[j-1][2])
        dp[j][1] += min(dp[j-1][0], dp[j-1][2])
        dp[j][2] += min(dp[j-1][0], dp[j-1][1])

    for j in range(3):
        if i != j: # N번째 집은 선택한 rgb 이외만
            ans = min(ans, dp[N-1][j])
            
print(ans)