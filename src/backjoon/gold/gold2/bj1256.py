n, m, k = map(int, input().split())
dp = [[0] * (m + 1) for _ in range(n + 1)]

for j in range(1, m + 1):
    dp[0][j] = 1

for i in range(1, n + 1):
    dp[i][0] = 1
    for j in range(1, m + 1): # a로 시작할 경우와 b로 시작할 경우를 더한다
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

ans = ""
def s(a, z, k_):
    global ans
    if a <= 0 or z <= 0: # a만 남거나 z만 남은경우 남은것들을 다 더해줌
        ans += 'a' * a if a else 'z' * z
        return 

    if dp[a - 1][z] >= k_: # k가 a로 시작한 경우의 수 이하이면 맨앞은 a라는 뜻이므로
        ans += 'a'
        s(a - 1, z, k_)
    else: # k가 a로 시작한 경우의 수 초과면 맨앞은 z라는 뜻이므로
        ans += 'z' 
        s(a, z - 1, k_ - dp[a - 1][z])

if k > dp[n][m]:
    ans += "-1"
else:
    s(n, m, k)
print(ans)