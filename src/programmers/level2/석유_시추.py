import sys
sys.setrecursionlimit(10**7)

def dfs(land, y, x, visit, id, rand_id):
    visit[y][x] = True
    rand_id[y][x] = id
    size = 1

    for dy, dx in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
        ny = y + dy
        nx = x + dx
        if 0 <= ny < len(land) and 0 <= nx < len(land[0]) and not visit[ny][nx] and land[ny][nx] == 1:
            size += dfs(land, ny, nx, visit, id, rand_id)

    return size

def solution(land):
    size = [0]
    visit = [[False] * len(land[0]) for _ in range(len(land))]
    land_id = [[0] * len(land[0]) for _ in range(len(land))]
    id = 1
    for i in range(len(land)):
        for j in range(len(land[0])):
            if not visit[i][j] and land[i][j] == 1:
                oil = dfs(land, i, j, visit, id, land_id)
                size.append(oil)
                id += 1

    ans = 0
    for i in range(len(land[0])):
        visit = set([0])
        oil = 0
        for j in range(len(land)):
            if land_id[j][i] not in visit:
                visit.add(land_id[j][i])
                oil += size[land_id[j][i]]

        ans = max(ans, oil)

    return ans