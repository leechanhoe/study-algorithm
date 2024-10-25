N, K = map(int, input().split())
now = 0
for i in range(1, K + 1):
    now += i

if N < now:
    print(-1)
    exit(0)

while now <= N:
    if now == N:
        print(K - 1)
        exit(0)
    now += K

print(K)
