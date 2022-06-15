import sys
import copy
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
g = [] # 땅 (ground)

for i in range(N):
        g.append(list(map(int, input().strip().split())))

def get_ps(_g): #누적합 구하는 함수
    ps = [[0] * (N + 1)for _ in range(N + 1)] # 누적합 (prefix sum)
    for i in range(N):
        for j in range(N):
            if not i: # 0행과 0열은 그대로
                if not j:
                    ps[i][j] = _g[i][j]
                else:
                    ps[i][j] = _g[i][j] + ps[i][j - 1]
            elif not j and i:
                ps[i][j] = _g[i][j] + ps[i - 1][j]
            else: # 나머지
                ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + _g[i][j]
    return ps

ans = 0
def get_rec(y, x, ps_): # 사각형 완전탐색
    global ans
    ps2 = copy.deepcopy(ps_)
    areas = {} # 딕셔너리에 좌상단 넓이들 저장해서 우하단에서 같은 땅넓이가 있으면 더해줌 

    for i in range(y + 1): # 좌상단
        for j in range(x + 1): # 누적합 구할때 추가로 (N+1)^2에 N초과칸에 0을 넣어줘서 -1이여도 인덱싱 가능
            area = ps2[y][x] - ps2[i - 1][x] - ps2[y][j - 1] + ps2[i - 1][j - 1]
            if area in areas:
                areas[area] += 1
            else:
                areas[area] = 1

    ps2 = copy.deepcopy(ps_)
    for i in range(y + 1, N): # 우하단
        for j in range(x + 1, N):
            area = ps2[i][j] - ps2[i][x] - ps2[y][j] + ps2[y][x]
            if area in areas:
                ans += areas[area]

rev_g = [] 
for i in range(N): # 좌우만 뒤집어서 하면 우상단 좌하단도 가능
    rev_g.append(list(reversed(g[i])))
for i in range(N - 1):
    for j in range(N - 1):
        get_rec(i, j, get_ps(g))
        get_rec(i, j, get_ps(rev_g))
print(ans)