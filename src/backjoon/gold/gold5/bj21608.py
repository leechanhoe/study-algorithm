import sys
input = lambda : sys.stdin.readline().rstrip()
N = int(input())
stu = []
dyx = [(-1, 0), (0, -1), (0, 1), (1, 0)]
for _ in range(N * N):
    stu.append(list(map(int, input().split())))
seat = [[0] * (N) for _ in range(N)]

for s in stu:
    fav = []
    blank = [[0] * (N) for _ in range(N)]
    max_fav = 0
    for i in range(N):
        for j in range(N):
            if seat[i][j]:
                continue
            fa = 0
            for yx in dyx:
                if not (0 <= i + yx[0] < N and 0 <= j + yx[1] < N):
                    continue
                if(seat[i + yx[0]][j + yx[1]] in s[1:]):
                    fa += 1
                elif(seat[i + yx[0]][j + yx[1]] == 0):
                    blank[i][j] += 1

            if fa >= max_fav:
                if fa > max_fav:
                    max_fav = fa
                    fav.clear()
                fav.append((i, j))

    b = []
    max_b = 0
    for f in fav:
        if blank[f[0]][f[1]] >= max_b:
            if blank[f[0]][f[1]] > max_b:
                max_b = blank[f[0]][f[1]]
                b.clear()
            b.append(f)
    seat[b[0][0]][b[0][1]] = s[0]

ans = 0
sorted_stu = [0] + sorted(stu)
for i in range(N):
    for j in range(N):
        fa = 0
        for yx in dyx:
            if not (0 <= i + yx[0] < N and 0 <= j + yx[1] < N):
                continue
            if(seat[i + yx[0]][j + yx[1]] in sorted_stu[seat[i][j]][1:]):
                fa += 1
        ans += 10 ** (fa - 1) if fa else 0
print(ans)