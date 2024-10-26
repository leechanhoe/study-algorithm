N = int(input())
ans = 0
for _ in range(N):
    a, b, c = map(int, input().split())
    if a == b == c:
        ans = max(ans, 10000 + a * 1000)
    elif a == b or a == c:
        ans = max(ans, 1000 + a * 100)
    elif b == c:
        ans = max(ans, 1000 + b * 100)
    else:
        ans = max(ans, max((a, b, c)) * 100)

print(ans)
