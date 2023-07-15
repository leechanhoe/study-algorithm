import sys
input = lambda : sys.stdin.readline().rstrip()

N, K = map(int, input().split())
ph = input()
visit = [False] * N
ans = 0

for i in range(N):
    if ph[i] == 'P':
        for j in range(-K, K + 1):
            now = i + j
            if 0 <= now < N and ph[now] == 'H' and not visit[now]:
                visit[now] = True
                ans += 1
                break

print(ans)