now = 0
ans = 0
for _ in range(10):
    o, i = map(int, input().split())
    now -= o
    now += i
    ans = max(ans, now)
print(ans)