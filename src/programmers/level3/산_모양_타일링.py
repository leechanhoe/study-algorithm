def solution(n, tops):
    dp = [0] * (2 * n + 2)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, 2 * n + 2):
        dp[i] = (dp[i-1] + dp[i-2]) % 10007
        if tops[(i - 2) // 2] and i % 2 == 0:
                dp[i] = (dp[i] + dp[i-1]) % 10007

    return dp[2 * n + 1] % 10007