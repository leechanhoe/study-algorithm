import sys
input = sys.stdin.readline

arr = []
for i in range(int(input())):
    n, d, m, y = input().split()
    y, m, d = map(int, (y, m, d))
    arr.append((y, m, d, n))
arr.sort()
print(arr[-1][3])
print(arr[0][3])