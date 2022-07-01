import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dp = [[0] * N for _ in range(N)]
arr =[*map(int, input().split())]
M = int(input())
# 크기가 1이면 1
for i in range(N):
    dp[i][i] = 1
# 크기가 2인데 같은수면 1
for i in range(N - 1):
    if arr[i] == arr[i+1]:
        dp[i][i+1] = 1
# 크기가 3이상이고 중간이 1이고 양끝이 같으면 1
for i in range(2, N): # e - s의 크기
    for j in range(N - i): # 오른쪽으로 한칸씩
        if dp[j+1][i+j-1] and arr[j] == arr[i+j]:
            dp[j][i+j] = 1


for i in range(M):
    s, e = map(int, input().split())
    print(dp[s-1][e-1])