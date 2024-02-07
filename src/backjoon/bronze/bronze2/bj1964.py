N = int(input())
ans = 5
for i in range(2, N + 1):
    ans += 5 * i - (i * 2 - 1)
    ans %= 45678
print(ans)