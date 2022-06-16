from itertools import combinations_with_replacement
N, M = map(int, input().split())
nums = sorted(list(set(map(int, input().split()))))
for com in combinations_with_replacement(nums, M):
    print(*com)