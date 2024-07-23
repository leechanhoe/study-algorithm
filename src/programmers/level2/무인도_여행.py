import sys
sys.setrecursionlimit(10 ** 6)
visit = [[False] * 101 for _ in range(101)]

def dfs(y, x, maps):
    visit[y][x] = True
    score = int(maps[y][x])
    for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        ny = y + dy
        nx = x + dx
        if 0 <= ny < len(maps) and 0 <= nx < len(maps[ny]) and maps[ny][nx] != 'X' and not visit[ny][nx]:
            score += dfs(ny, nx, maps)
    return score
    
def solution(maps):
    answer = []
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if not visit[i][j] and maps[i][j] != 'X':
                answer.append(dfs(i, j, maps))
    
    answer.sort()
    if not answer:
        answer = [-1]
    return answer