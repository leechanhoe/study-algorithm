import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
board = [[*map(int, input().split())] for _ in range(N)]
islands = [0]
dist = [[10] * 7 for _ in range(7)]
parent = [*range(7)]
edge = []

def bfs(i, j, visit, islandNum):
    visit[i][j] = True

    dq = deque()
    dq.append((i, j))
    island = [[i, j]]
    board[i][j] = islandNum
    while dq:
        y, x = dq.popleft()

        for dir in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
            ny = y + dir[0]
            nx = x + dir[1]
            if 0 <= ny < N and 0 <= nx < M and not visit[ny][nx] and board[ny][nx] == 1:
                visit[ny][nx] = True
                board[ny][nx] = islandNum
                dq.append([ny, nx])
                island.append([ny, nx])

    return island

def findIsland():
    visit = [[False] * M for _ in range(N)]
    islandNum = 0
    for i in range(N):
        for j in range(M):
            if not visit[i][j] and board[i][j] == 1:
                islandNum += 1
                islands.append(bfs(i, j, visit, islandNum))

def makeBridge():
    for i in range(1, len(islands)):
        for y, x in islands[i]:
            for dir in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
                ny = y + dir[0]
                nx = x + dir[1]
                if 0 <= ny < N and 0 <= nx < M and board[ny][nx] == 0:
                    nny = ny + dir[0]
                    nnx = nx + dir[1]
                    leng = 1
                    while 0 <= nny < N and 0 <= nnx < M:
                        if board[nny][nnx] > 0:
                            if leng >= 2 and board[nny][nnx] != i:
                                dist[i][board[nny][nnx]] = min(dist[i][board[nny][nnx]], leng)
                            break
                        leng += 1
                        nny += dir[0]
                        nnx += dir[1]

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

def spanningTree():
    for i in range(1, len(islands)):
        for j in range(i + 1, len(islands)):
            if dist[i][j] < 10:
                edge.append((i, j, dist[i][j]))

    edge.sort(key=lambda x : x[2])

    ans = 0
    for a, b, c in edge:
        if find(a) != find(b):
            union(a, b)
            ans += c

    for i in range(1, len(islands)): # 모든 섬이 연결되어있나 체크
        find(i)
        if parent[i] != 1:
            return -1
    return ans
    
findIsland()
makeBridge()
print(spanningTree())