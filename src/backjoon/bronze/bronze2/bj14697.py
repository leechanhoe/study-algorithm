a, b, c, n = map(int, input().split())

for i in range(0, n+1, a):
    for j in range(0, n+1, b):
        for k in range(0, n+1, c):
            sum_ = i + j + k
            if sum_ == n:
                print(1)
                exit(0)
            elif sum_ > n:
                break

print(0)