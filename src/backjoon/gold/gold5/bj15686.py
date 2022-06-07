from itertools import combinations

n, m = map(int, input().split())
home = []
chi = []
for i in range(n):
    j = 0
    for j, val in enumerate(input().split()):
        if val == '1':
            home.append((i,j))
        elif val == '2':
            chi.append((i,j))

ans = 987654321
for ch in combinations(chi, m):
    sum_d = 0 #조합에 따른 치킨 거리
    for h in home:
        min_d = 987654321 #집집마다 치킨집까지의 최소거리 구하기
        for c in ch:
            min_d = min(min_d, abs(h[0] - c[0]) + abs(h[1] - c[1]))
        sum_d += min_d
    ans = min(ans, sum_d)
print(ans)