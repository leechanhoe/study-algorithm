import heapq
hq = []
n = int(input())

for _ in range(n):
    for num in map(int, input().split()):
        if(len(hq) >= n):
            heapq.heappushpop(hq, num)
        else:
            heapq.heappush(hq, num)

print(heapq.heappop(hq))