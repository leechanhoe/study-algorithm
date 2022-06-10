from itertools import permutations
import sys

input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))

opr_cnt = []
for i, cnt in enumerate(map(int, input().split())):
    opr_cnt += [i] * cnt

min_val = 1987654321
max_val = -1987654321
for oprs in set(permutations(opr_cnt, n - 1)):
    val = nums[0]
    for i, opr in enumerate(oprs, 1):
        if opr == 0:
            val += nums[i]
        elif opr == 1:
            val -= nums[i]
        elif opr == 2:
            val *= nums[i]
        else:
            val = val // nums[i] if val >= 0 else -(-val // nums[i])
    max_val = max(max_val, val)
    min_val = min(min_val, val)

print(max_val)
print(min_val)