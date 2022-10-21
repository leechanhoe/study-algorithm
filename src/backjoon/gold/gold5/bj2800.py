import sys
from itertools import combinations
input = lambda : sys.stdin.readline().rstrip()

s = input()
ans = set()
stk = []
tmp = []

for i, ch in enumerate(s):
    if ch == '(':
        stk.append(i)
    elif ch == ')':
        tmp.append((stk.pop(), i))

for i in range(1, len(tmp) + 1):
    c = combinations(tmp, i)
    for j in c:
        remov = list(s)

        for le, ri in j:
            remov[ri] = remov[le] = ''
        ans.add(''.join(remov))

ans = sorted(list(ans))
for a in ans:
    print(a)