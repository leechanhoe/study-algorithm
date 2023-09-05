import sys
input = lambda : sys.stdin.readline().rstrip()

K, L = map(int, input().split())

vaild = [True] * L
num = [input() for _ in range(L)]
dic = {}

for i in range(L - 1, -1 ,-1):
    if num[i] not in dic.keys():
        dic[num[i]] = True
    else:
        vaild[i] = False

cnt = 0
for i in range(L):
    if vaild[i]:
        print(num[i])
        cnt += 1

        if cnt == K:
            break