import sys
import bisect
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
title = {}
for i in range(N):
    name, val = input().split()
    val = int(val)
    if val not in title.keys():
        title[val] = name
arr = sorted(title.keys())

for i in range(M):
    val = int(input())
    idx = bisect.bisect_left(arr, val)
    print(title[arr[idx]])