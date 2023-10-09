mush = [int(input()) for _ in range(10)]

sum_ = 0
for m in mush:
    sum_ += m
    if 100 <= sum_:
        if sum_ - 100 <= 100 - (sum_ - m):
            print(sum_)
        else:
            print(sum_ - m)
        exit(0)
print(sum_)