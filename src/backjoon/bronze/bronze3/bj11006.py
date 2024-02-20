T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    cut = M * 2 - N
    print(cut, M - cut)