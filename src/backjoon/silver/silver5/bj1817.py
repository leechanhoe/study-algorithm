N, M = map(int, input().split())
if N == 0:
    print(0)
    exit(0)

box = list(map(int, input().split()))
now = 0
ans = 1
for b in box:
    now += b
    if M < now:
        ans += 1
        now = b

print(ans)
