import sys
input = sys.stdin.readline

def sort_(row, col, arr):
    ret = [[] for _ in range(max(row, col))]
    maxRow = maxCol = 3
    if row >= col:
        for i in range(row):
            cnt = [[0, i] for i in range(101)]
            for j in range(col):
                cnt[arr[i][j]][0] += 1
            cnt.sort()
            for c in cnt:
                if c[0] == 0 or c[1] == 0:
                    continue
                ret[i].append(c[1])
                ret[i].append(c[0])
                if len(ret[i]) == 100:
                    break
            maxCol = max(maxCol, len(ret[i]))
        maxRow = row

        for i in range(maxRow):
            while len(ret[i]) < maxCol:
                ret[i].append(0)
    else:
        for j in range(col):
            cnt = [[0, i] for i in range(101)]
            for i in range(row):
                cnt[arr[i][j]][0] += 1
            cnt.sort()
            for c in cnt:
                if c[0] == 0 or c[1] == 0:
                    continue
                ret[j].append(c[1])
                ret[j].append(c[0])
                if len(ret[j]) == 100:
                    break
            maxCol = max(maxCol, len(ret[j]))
        maxRow = col
        ret2 = [[0] * maxRow for _ in range(maxCol)]

        for i in range(maxRow):
            while len(ret[i]) < maxCol:
                ret[i].append(0)

        for i in range(maxCol):
            for j in range(maxRow):
                ret2[i][j] = ret[j][i]
        ret = ret2
        maxCol, maxRow = maxRow, maxCol

    return maxRow, maxCol, ret

r, c, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(3)]
nr = nc = 3
for t in range(0, 101):
    if(r-1 < nr and c-1 < nc and arr[r-1][c-1] == k):
        print(t)
        exit(0)
    nr, nc, arr = sort_(nr, nc, arr)
    # for i in arr:
    #     print(*i)
print(-1)