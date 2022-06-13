import math
dp = [0] * 12

def match(n):
    ans = []
    for three in range(n // 3 + 1):
        for two in range(n // 2 + 1):
            for one in range(n + 1):
                if one * 1 + two * 2 + three * 3 == n:
                    ans.append((one, two, three))
                    break
    
    for i in ans:
        a = math.factorial(sum(i))
        for j in i:
            a //= math.factorial(j)
        dp[n] += a
    return dp[n]

for _ in range(int(input())):
    n = int(input())
    if dp[n]:
        print(dp[n])
    else:
        print(match(n))