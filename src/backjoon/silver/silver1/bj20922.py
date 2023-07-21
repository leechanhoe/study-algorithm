import sys
input = lambda : sys.stdin.readline().rstrip()

N, K = map(int, input().split())
arr = list(map(int, input().split()))
num = [0] * 100001
le = 0
ri = 0
ans = 1

while ri < N and le < N: 
    if num[arr[ri]] == K:
        while arr[le] != arr[ri]:
            num[arr[le]] -= 1
            le += 1
        num[arr[le]] -= 1
        le += 1

    num[arr[ri]] += 1
    ri += 1

    ans = max(ans, ri - le)

print(ans)