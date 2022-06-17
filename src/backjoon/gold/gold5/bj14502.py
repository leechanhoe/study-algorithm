from collections import deque
import copy

N, M = map(int, input().split())
area = []
virus = []
for i in range(N):
    area.append(list(map(int, input().split())))
    for j, val in enumerate(area[-1]):
        if val == 2:
            virus.append((i, j))

def is_vaild(y, x):
    return 0 <= y < N and 0 <= x < M

def spread(area):
    virus_num = len(virus)
    for y, x in virus:
        move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        dq = deque()
        dq.append((y, x))
        while dq:
            _y, _x = dq.popleft()
            for dir in move:
                ny = _y + dir[0]
                nx = _x + dir[1]
                if is_vaild(ny, nx) and area[ny][nx] == 0:
                    area[ny][nx] += 2
                    virus_num += 1
                    dq.append((ny, nx))
    return virus_num

virus_num = 1987654321
def build_wall(y, x, area, wall):
    if wall == 3:
        global virus_num
        narea = copy.deepcopy(area)
        virus_num = min(virus_num, spread(narea))    
        return

    for i in range(y, N):
        for j in range(M):
            if i == y and j < x:
                continue
            if area[i][j] == 0:
                area[i][j] = 1
                build_wall(i, j, area, wall + 1)
                area[i][j] = 0

wall = 3
for i in range(N):
    for j in range(M):
        if area[i][j] == 0:
            build_wall(i, j, area, 0)
        elif area[i][j] == 1:
            wall += 1
print(N * M - wall - virus_num)        