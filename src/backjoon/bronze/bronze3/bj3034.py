import math

N, W, H = map(int, input().split())
limit = math.sqrt(W ** 2 + H ** 2)
for _ in range(N):
    l = int(input())
    if l <= limit:
        print("DA")
    else:
        print("NE")
