from bisect import bisect_right, bisect_left

N = int(input())
U = [int(input()) for _ in range(N)]
U.sort()
ans = 0
se = set()

for n1 in U:
    for n2 in U:
        se.add(n1 + n2)

for i in range(N - 1, -1, -1):
    for j in range(i):
        if U[i] - U[j] in se:
            print(U[i])
            exit(0)
