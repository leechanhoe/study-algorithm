from collections import defaultdict
from heapq import heappush, heappop
import sys

input = lambda: sys.stdin.readline().rstrip()

N, L = map(int, input().split())
arr = list(map(int, input().split()))
ans = []
pq = []
dic = defaultdict(int)

for i in range(N):
    heappush(pq, arr[i])
    dic[arr[i]] += 1

    prev = i - L
    if 0 <= prev:
        dic[arr[prev]] -= 1
        while pq[0] not in dic or dic[pq[0]] == 0:
            heappop(pq)

    ans.append(pq[0])

print(*ans)
