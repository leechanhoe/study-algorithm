import sys
input = sys.stdin.readline

N, C = map(int, input().split())
M = int(input())
boxs = []
for _ in range(M):
    boxs.append(list(map(int, input().split())))
boxs.sort(key=lambda x : x[1])

box = [C] * (N+1)
ans = 0
for start, end, num in boxs:
    _min = min(box[start:end])
    _min = min(_min, num)

    for i in range(start, end):
        box[i] -= _min
    ans += _min

print(ans)