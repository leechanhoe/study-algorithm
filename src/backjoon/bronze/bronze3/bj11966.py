N = int(input())
print(1 if (N & (N - 1)) == 0 and N != 0 else 0)