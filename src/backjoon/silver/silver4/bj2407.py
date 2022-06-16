import math
N, M = map(int, input().split())
print(math.factorial(N) // math.factorial(M) // math.factorial(N - M))