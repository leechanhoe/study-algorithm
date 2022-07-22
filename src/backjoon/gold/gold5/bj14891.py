gears = []
for i in range(4):
    gears.append(list(map(int, list(input()))))

def rotate(i, dir):
    ret = [0] * 8
    for j in range(8):
        if dir == 1:
            ret[j] = gears[i][j-1]
        else:
            ret[j] = gears[i][(j + 1) % 8]
    gears[i] = ret

for _ in range(int(input())):
    num, dir = map(int, input().split())
    num -= 1
    linked = [False] * 4 # 지금 돌리려는 톱니바퀴와 연결되있으면 True
    linked[num] = True

    for i in range(num, 3): # 우측 연결되있나 체크
        if gears[i][2] != gears[i+1][6]:
            linked[i+1] = True
        else:
            break
    for i in range(num, 0, -1): # 좌측 연결되있나 체크
        if gears[i][6] != gears[i-1][2]:
            linked[i-1] = True
        else:
            break

    for i in range(4):
        if linked[i]: # 1/3 , 2/4 끼리 같은방향으로 도므로
            rotate(i, dir if num % 2 == i % 2 else -dir)

ans = 0
for i in range(4):
    if gears[i][0]:
        ans += 2 ** i
print(ans)