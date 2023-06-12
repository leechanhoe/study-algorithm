import heapq

N = int(input())
me = int(input())
if N == 1:
    print(0)
    exit(0)
hq = []
for i in range(1, N):
    heapq.heappush(hq, -int(input()))

ans = 0
while me <= -hq[0]:
    tmp = -heapq.heappop(hq)
    tmp -= 1
    me += 1
    heapq.heappush(hq, -tmp)
    ans += 1

print(ans)