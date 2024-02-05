N = int(input())

ans = 0
for a in range(N + 1):
    for b in range(a, N + 1):
        ans += a + b

print(ans)