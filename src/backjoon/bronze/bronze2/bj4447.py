from collections import Counter

N = int(input())
for _ in range(N):
    name = input()
    name_small = name.lower()
    cnt = Counter(name_small)
    if cnt['g'] > cnt['b']:
        print(name + ' is GOOD')
    elif cnt['g'] == cnt['b']:
        print(name + ' is NEUTRAL')
    else:
        print(name + ' is A BADDY')