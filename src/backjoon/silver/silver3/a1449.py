import sys

input = sys.stdin.readline
N, L = map(int, input().split())
leaks = [x for x in map(int, input().split())]
leaks.sort()

fixed = 0
cnt = 0
for loc in leaks:
    if fixed < loc:
        fixed = loc + L - 1
        cnt += 1
print(cnt)