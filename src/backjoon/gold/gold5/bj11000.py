import sys
import heapq
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
clas = []
for _ in range(N):
    clas.append(tuple(map(int, input().split())))
clas.sort()

room = []
room.append(clas.pop(0)[1])
for c in clas:
    if c[0] >= room[0]:
        heapq.heappop(room)
    heapq.heappush(room, c[1])
print(len(room))