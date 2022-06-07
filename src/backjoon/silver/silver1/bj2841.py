import sys
input = sys.stdin.readline
guitar = [[] for _ in range(7)]
N, P = map(int, input().split())

cnt = 0
for i in range(N):
    string, fret = map(int, input().split())
    if not len(guitar[string]): #스택이 비었을때
        guitar[string].append(fret)
        cnt += 1
    else:
        if guitar[string][-1] < fret: #프렛이 클때
            guitar[string].append(fret)
            cnt += 1
        elif guitar[string][-1] == fret: #같을때
            continue
        else: #작을때
            while len(guitar[string]) and guitar[string][-1] > fret:
                guitar[string].pop()
                cnt += 1
            if len(guitar[string]) and guitar[string][-1] == fret:
                continue
            guitar[string].append(fret)
            cnt += 1
print(cnt)