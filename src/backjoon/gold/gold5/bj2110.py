import sys
input = lambda : sys.stdin.readline().rstrip()

N, C = map(int, input().split())
house = []
for _ in range(N):
    house.append(int(input()))
house.sort()
start = 1
end = house[-1] - house[0]
ans = 0

while start <= end:
    mid = (start + end) // 2
    cnt = 1
    cur = house[0]
    for i in range(1, N):
        if house[i] >= mid + cur:
            cnt += 1
            cur = house[i]

    if cnt >= C:
        start = mid + 1
        ans = mid
    else:
        end = mid - 1
print(ans)