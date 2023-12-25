M = int(input())
N = int(input())

ans = []
for i in range(101):
    ii = i * i
    if M <= ii <= N:
        ans.append(ii)

if ans:
    print(sum(ans))
    print(ans[0])
else:
    print(-1)