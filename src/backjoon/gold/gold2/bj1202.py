import sys
import heapq
input = lambda : sys.stdin.readline().rstrip()

N, K = map(int, input().split())
jews = []
for _ in range(N):
    heapq.heappush(jews, tuple(map(int, input().split())))
bags = []
for _ in range(K):
    bags.append(int(input()))
bags.sort()

ans = 0
temp = []
for bag in bags:
    while jews and bag >= jews[0][0]:
        heapq.heappush(temp, -heapq.heappop(jews)[1])
    if temp:
        ans -= heapq.heappop(temp)
print(ans)