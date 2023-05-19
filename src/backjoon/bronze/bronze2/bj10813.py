N, M = map(int, input().split())
basket = list(range(N + 1))

for _ in range(M):
    i, j = map(int, input().split())
    basket[i], basket[j] = basket[j], basket[i]

print(*basket[1:])