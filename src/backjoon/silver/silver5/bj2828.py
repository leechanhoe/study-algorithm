N, M = map(int, input().split())
J = int(input())
ans = 0
now = 1
for _ in range(J):
    apple = int(input())
    if apple < now:
        ans += now - apple
        now = apple
    elif now + M - 1 < apple:
        ans += apple - (now + M - 1)
        now = apple - M + 1
print(ans)