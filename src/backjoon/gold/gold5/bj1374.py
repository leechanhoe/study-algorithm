import heapq

st = []
en = []
ans = 0
N = int(input())
for i in range(N):
    idx, start, end = map(int, input().split())
    heapq.heappush(st, [start, end, idx])

start, end, idx = heapq.heappop(st)
heapq.heappush(en, end)
while st:
    start, end, idx = heapq.heappop(st)
    if en[0] <= start:
        heapq.heappop(en)
    heapq.heappush(en, end)

print(len(en))