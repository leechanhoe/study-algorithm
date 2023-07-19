import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
ans = N
memo = {input() : 1 for _ in range(N)}

for _ in range(M):
    for word in input().split(','):
        if word in memo.keys() and memo[word] == 1:
            memo[word] = 0
            ans -= 1
    print(ans)