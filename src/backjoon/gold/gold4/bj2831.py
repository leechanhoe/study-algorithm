import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
man = [*map(int, input().split())]
wo = [*map(int, input().split())]
man_up = []
man_down = []
wo_up = []
wo_down = []

for h in man:
    if 0 < h:
        man_up.append(h)
    else:
        man_down.append(abs(h))

for h in wo:
    if 0 < h:
        wo_up.append(h)
    else:
        wo_down.append(abs(h))

man_up.sort()
man_down.sort()
wo_up.sort()
wo_down.sort()

ans = 0
m = 0
w = 0
while m < len(man_up) and w < len(wo_down):
    if man_up[m] < wo_down[w]:
        ans += 1
        m += 1
    w += 1

m = 0
w = 0
while m < len(man_down) and w < len(wo_up):
    if man_down[m] > wo_up[w]:
        ans += 1
        w += 1
    m += 1

print(ans)