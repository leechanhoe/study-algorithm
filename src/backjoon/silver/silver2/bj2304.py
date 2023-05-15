N = int(input())
h = [0] * 1001

maxh = 0
maxIdx = 0
for i in range(N):
    a, b = map(int, input().split())
    h[a] = b
    
    if maxh < b:
        maxh = b
        maxIdx = a

ans = maxh
nowmax = 0
for i in range(maxIdx):
    nowmax = max(h[i], nowmax)
    ans += nowmax

nowmax = 0
for i in range(1000, maxIdx, -1):
    nowmax = max(h[i], nowmax)
    ans += nowmax

print(ans)