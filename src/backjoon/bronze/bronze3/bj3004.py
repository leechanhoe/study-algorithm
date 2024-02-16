N = int(input())
now = 1
ans = 1
for i in range(1, N + 1):
    if i % 2 == 0:
        now += 1
    ans += now
print(ans)