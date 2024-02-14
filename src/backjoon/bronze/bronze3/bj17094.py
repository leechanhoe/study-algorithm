from collections import Counter

l = int(input())
s = input()
cnt = Counter(s)

if cnt['2'] > cnt['e']:
    print(2)
elif cnt['2'] == cnt['e']:
    print('yee')
else:
    print('e')