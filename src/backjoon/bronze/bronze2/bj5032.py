e, f, c = map(int, input().split())
remain = e + f
ans = 0
while remain >= c:
    remain -= c
    remain += 1
    ans += 1

print(ans)