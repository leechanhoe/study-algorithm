N = int(input())
inp = {input() : i for i in range(N)}
out = [input() for _ in range(N)]
visit = [False] * N
ans = 0

for i in inp:
    for j in range(N):
        if inp[i] < inp[out[j]] and not visit[j]:
            ans += 1
            visit[j] = True
        if i == out[j]:
            break
print(ans)