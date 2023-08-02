N = int(input())

x1 = y1 = 10000
x2 = y2 = -10000
for i in range(N):
    x, y = map(int, input().split())
    x1 = min(x1, x)
    y1 = min(y1, y)
    x2 = max(x2, x)
    y2 = max(y2, y)

print((x2 - x1) * (y2 - y1))