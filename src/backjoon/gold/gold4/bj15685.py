import sys
input = lambda : sys.stdin.readline()

curves = []
N = int(input())
for _ in range(N):
    x, y, d, g = map(int, input().split())
    curves.append([x, y, [d], g])
mv = [(1, 0), (0, -1), (-1, 0), (0, 1)]
chk = [[False] * 101 for _ in range(101)]

def make(c):
    for _ in range(c[3]): # 드래곤커브가 만들어지는 방향들 저장
        for i in range(1, len(c[2]) + 1):
            c[2].append((c[2][-i-i+1]-2 % 4 - 1) % 4)

    chk[c[0]][c[1]] = True
    curx = c[0]
    cury = c[1]
    for dir in c[2]: # 만든 방향들을 이용해 드래곤커브 그리기
        curx += mv[dir][0]
        cury += mv[dir][1]
        chk[curx][cury] = True
        
for i in range(N):
    make(curves[i])

ans = 0
for i in range(1, 101):
    for j in range(1, 101):
        if chk[i][j] and chk[i][j-1] and chk[i-1][j] and chk[i-1][j-1]:
            ans += 1
print(ans)