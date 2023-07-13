import sys
from functools import cmp_to_key
input = lambda : sys.stdin.readline().rstrip()

def cmp(a, b):
    if a[1] < b[1]:
        return 1
    elif a[1] > b[1]:
        return -1
    else:
        if len(a[0]) < len(b[0]):
            return 1
        elif len(a[0]) > len(b[0]):
            return -1
        else:
            if a[0] < b[0]:
                return -1
            elif a[0] > b[0]:
                return 1
            else:
                return 0

N, M = map(int, input().split())
dic = {}
for i in range(N):
    word = input()
    if M <= len(word):
        if word not in dic.keys():
            dic[word] = 1
        else:
            dic[word] += 1

ans = sorted(dic.items(), key=cmp_to_key(cmp))
for word, _ in ans:
    print(word)