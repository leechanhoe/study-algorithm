from itertools import combinations
N, M = map(int, input().split())
nums = [i for i in range(1, N + 1)]
for com in combinations(nums, M):
    print(*com)