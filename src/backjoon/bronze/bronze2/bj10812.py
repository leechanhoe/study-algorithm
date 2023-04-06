N, M = map(int, input().split())
li = list(range(1, N+1))

for _ in range(M):
    i, j, k = map(int, input().split())
    li = li[:i-1] + li[k-1:j] + li[i-1:k-1] + li[j:]
print(*li)