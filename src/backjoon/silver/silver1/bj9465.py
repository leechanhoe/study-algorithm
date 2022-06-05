for _ in range(int(input())):
    n = int(input())
    sticker = [list(map(int, input().split())) for _ in range(2)]
    dp = [[0] * n for _ in range(2)]

    for i in range(2): 
        dp[i][0] = sticker[i][0]
        if n > 1:
            dp[i][1] = sticker[i ^ 1][0] + sticker[i][1]

    for j in range(2, n):
        for i in range(2): # 하나 추가했을 때 선택 가능한 건 전 열의 반대 행과 전전 열의 반대 행
            dp[i][j] = max(dp[i ^ 1][j - 1], dp[i ^ 1][j - 2]) + sticker[i][j]
    print(max(dp[0][n - 1], dp[1][n - 1]))