N = int(input())
h = list(map(int, input().split()))
ans = [0] * N

for i in range(N):
    cnt = 0
    for j in range(N):
        if ans[j] == 0:
            if h[i] == cnt:
                ans[j] = i + 1
                break
            cnt += 1

print(*ans)