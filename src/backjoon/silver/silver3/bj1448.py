import sys

input = lambda: sys.stdin.readline().rstrip()

N = int(input())
arr = [int(input()) for _ in range(N)]
arr.sort(reverse=True)

for i in range(N - 2):
    if arr[i] < arr[i + 1] + arr[i + 2]:
        print(arr[i] + arr[i + 1] + arr[i + 2])
        exit(0)

print(-1)
