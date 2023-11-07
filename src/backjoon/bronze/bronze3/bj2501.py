r = []
N, K = map(int, input().split())
for i in range(1, N + 1):
    if N % i == 0:
        r.append(i)
if len(r) < K:
    print(0)
else:
    print(r[K-1])