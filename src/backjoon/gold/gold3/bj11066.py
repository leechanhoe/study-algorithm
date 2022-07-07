import sys
input = lambda : sys.stdin.readline().rstrip()

for i in range(int(input())):
    N = int(input())
    files = [0] + list(map(int, input().split()))
    ps = [0] * (N + 1) # 누적합
    for i in range(1, N + 1):
        ps[i] = ps[i-1] + files[i]

    dp = [[0] * (N + 1) for _ in range(N + 1)] # dp[i][j] = i부터 j까지(j포함) 합하는데 필요한 최소 비용
    for i in range(2, N + 1): # 부분 파일의 길이
        for j in range(1, N + 2 - i): # 시작점  
            dp[j][j+i-1] = min([dp[j][j+k] + dp[j+k+1][j+i-1] for k in range(i-1)]) + (ps[j+i-1] - ps[j-1])
    print(dp[1][N]) # 파일 길이를 2부터 N까지 늘려가면서 구할 수 있다. 파일 길이 3은 1과 2로 구성되어있으니 길이2가 dp에 있다 