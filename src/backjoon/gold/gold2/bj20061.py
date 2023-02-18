import sys
input = lambda : sys.stdin.readline().rstrip()

green = [[False] * 4 for _ in range(6)]
blue = [[False] * 4 for _ in range(6)]
score = 0

def move(t, x, y, color, c):
    if c == 1:
        x1, x2 = 1, 1
        y1, y2 = y, y
        if t == 2:
            y2 = y + 1
        elif t == 3:
            x1 = 0

    else:
        x1, x2 = 1, 1
        y1, y2 = x, x
        if t == 2:
            x1 = 0
        elif t == 3:
            y2 = x + 1

    for i in range(1, 5):
        if(color[x1 + i][y1] or color[x2 + i][y2]):
            color[x1 + i - 1][y1] = True
            color[x2 + i - 1][y2] = True
            return
    color[x1 + 4][y1] = True
    color[x2 + 4][y2] = True

def remove(color, n):
    color.pop(n)
    color.insert(0, [False] * 4)

def checkFull(color):
    for i in range(6):
        if(sum(color[i]) == 4):
            global score
            score += 1
            remove(color, i)

def check01(color):
    if(sum(color[0]) > 0):
        remove(color, 5)
    if(sum(color[1]) > 0):
        remove(color, 5)

N = int(input())
for _ in range(N):
    t, x, y = map(int, input().split())
    move(t, x, y, green, 1)
    move(t, x, y, blue, 2)
    checkFull(green)
    checkFull(blue)
    check01(blue)
    check01(green)

tile = 0
for i in range(6):
    tile += sum(green[i])
    tile += sum(blue[i])
print(score)
print(tile)