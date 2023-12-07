T = int(input())
for _ in range(T):
    N = input()
    sum_ = str(int(N) + int(N[::-1]))
    if sum_ == sum_[::-1]:
        print("YES")
    else:
        print("NO")