N = int(input())

ans = [4]
a = 1
for i in range(N):
    a *= 2
    ans.append((a+1) * (a+1))

print(ans[N])