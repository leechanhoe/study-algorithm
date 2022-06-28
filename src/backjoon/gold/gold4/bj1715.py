import sys
import heapq

N = int(input())
nums = []
for _ in range(N):
    heapq.heappush(nums, int(sys.stdin.readline().rstrip()))

ans = 0
while len(nums) > 1:
    a = heapq.heappop(nums) + heapq.heappop(nums)
    ans += a
    heapq.heappush(nums, a)
print(ans)