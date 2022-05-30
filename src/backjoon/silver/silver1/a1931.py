import sys
input = sys.stdin.readline

meetings = [tuple(map(int, input().split())) for _ in range(int(input()))]
meetings.sort(key=lambda x: (x[1], x[0]))

t = 0
ans = 0
for start, end in meetings:
    if start >= t:
        ans += 1
        t = end
print(ans)