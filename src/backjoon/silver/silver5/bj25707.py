from functools import reduce

N = int(input())
beads = list(map(int, input().split()))
beads.sort()
min_length = reduce(
    lambda acc, i: acc + abs(beads[i] - beads[i - 1]), range(len(beads)), 0
)
print(min_length)
