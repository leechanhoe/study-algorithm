from collections import Counter

N, M = map(int, input().split())
ans = 0
for _ in range(N):
    cnt = Counter(input())
    ans += 1 if cnt['O'] > cnt['X'] else 0

print(ans)