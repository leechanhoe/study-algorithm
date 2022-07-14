import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
start = 0
end = N - 1
arr = [*map(int, input().split())]
mi = 2147483647
ans1 = ans2 = 0

while start < end:
    su = arr[start] + arr[end]
    if abs(su) < mi:
        mi = abs(su)
        ans1, ans2 = arr[start], arr[end]
    if su < 0:
        start += 1
    else:
        end -= 1

print(ans1, ans2)