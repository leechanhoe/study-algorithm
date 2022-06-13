from itertools import permutations

n = int(input())
ma = 0
for nums in permutations(map(int, input().split())):
    ma = max(ma, sum(abs(nums[i] - nums[i - 1]) for i in range(1, n)))
print(ma)