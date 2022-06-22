import heapq
import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
lhq = [-int(input())] # 최대힙
print(-lhq[0])
rhq = [] # 최소힙
for _ in range(N - 1):
    num = int(input())
    if -lhq[0] < num:
        heapq.heappush(rhq, num)
        if len(rhq) > len(lhq):
            heapq.heappush(lhq, -heapq.heappop(rhq))

    else:
        if len(rhq) < len(lhq):
            heapq.heappush(rhq, -heapq.heappop(lhq))
        heapq.heappush(lhq, -num)
    print(-lhq[0])