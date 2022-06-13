import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split())
memo = {}
for _ in range(N):
    a = input().strip().split()
    memo[a[0]] = a[1]
    
for _ in range(M):
    print(memo[input().strip()])