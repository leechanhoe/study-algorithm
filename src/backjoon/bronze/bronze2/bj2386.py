from collections import Counter

while(1):
    s = input()
    if s[0] == '#':
        break
    s = s.lower()
    cnt = Counter(s[2:])
    print(s[0], cnt[s[0]])