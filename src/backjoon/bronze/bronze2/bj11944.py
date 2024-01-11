N, M = input().split()
ans = N * int(N)
print(ans[:min(len(ans), int(M))])