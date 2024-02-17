from collections import Counter

zero = [0] * 1000001
for i in range(1000001):
    zero[i] = Counter(str(i))['0']

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    print(sum(zero[N:M+1]))