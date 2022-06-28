import sys
input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    grade = []
    for i in range(int(input())):
        grade.append(list(map(int, input().split())))

    dg = sorted(grade)
    mi = dg[0][1]
    ans = 1
    for i in dg:
        if i[1] < mi:
            mi = i[1]
            ans += 1
    print(ans)