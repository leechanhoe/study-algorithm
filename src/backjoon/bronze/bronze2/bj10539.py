N = int(input())
b = list(map(int, input().split()))
sum_ = 0
for i in range(N):
    val = b[i] * (i + 1) - sum_
    print(val, end=' ')
    sum_ += val