import heapq
import sys
input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())

hq = []
for c in map(int, input().split()):
    heapq.heappush(hq, c)

for _ in range(m):
    c1 = heapq.heappop(hq)
    c2 = heapq.heappop(hq)

    heapq.heappush(hq, c1 + c2)
    heapq.heappush(hq, c1 + c2)

print(sum(hq))