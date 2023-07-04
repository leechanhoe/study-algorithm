import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
words = [input() for _ in range(N)]
dic = {}
for word in words:
    sub = ""
    for i in range(len(word)):
        sub += word[i]
        if sub not in dic.keys():
            dic[sub] = 1
        else:
            dic[sub] += 1

li = list(filter(lambda x : x[1] >= 2, dic.items()))
li = sorted(li, key=lambda x : len(x[0]), reverse=True)
same = li[0][0]

cnt = 0
for word in words:
    if same == word[:len(same)]:
        print(word)
        cnt += 1
    
    if cnt == 2:
        break