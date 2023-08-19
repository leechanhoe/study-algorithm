N = int(input())
athlete = [input() for _ in range(N)]
inc = sorted(athlete)
dec = sorted(athlete, reverse=True)
flag = [True] * 2

for i in range(N):
    if athlete[i] != inc[i]:
        flag[0] = False
        break

for i in range(N):
    if athlete[i] != dec[i]:
        flag[1] = False
        break

if flag[0]:
    print("INCREASING")
elif flag[1]:
    print("DECREASING")
else:
    print("NEITHER")