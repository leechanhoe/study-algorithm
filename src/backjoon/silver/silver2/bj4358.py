import sys
input = lambda : sys.stdin.readline().rstrip()

dic = {}
cnt = 0
while 1:
    s = input()
    if not s:
        break
    if s in dic:
        dic[s] += 1
    else:
        dic[s] = 1
    cnt += 1

kind = sorted(dic.keys())
for tree in kind:
    pro = dic[tree] / cnt * 100
    print(tree, "%.4f" %pro)