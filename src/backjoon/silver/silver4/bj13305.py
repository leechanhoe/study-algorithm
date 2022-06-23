N = int(input())
road = list(map(int, input().split()))
station = list(map(int, input().split()))

ans = station[0] * road[0]
mi = station[0]
for i in range(1, N - 1):
    mi = min(mi, station[i])
    ans += mi * road[i]
print(ans)