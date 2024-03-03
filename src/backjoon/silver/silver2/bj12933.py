from collections import defaultdict

cnt = defaultdict(int)
prev = {'q': 'k', 'u' : 'q', 'a' : 'u', 'c' : 'a', 'k' : 'c'}
sound = []
inpu = input()
for ch in inpu:
    cnt[ch] += 1
    flag = False
    for i in range(len(sound)):
        if sound[i][-1] == prev[ch]:
            sound[i] = sound[i] + ch
            flag = True
            break
    
    if not flag:
        if ch == 'q':
            sound.append(ch)
        else:
            print(-1)
            exit(0)

if cnt['q'] == cnt['u'] == cnt['a'] == cnt['c'] == cnt['k']:
    print(len(sound))
else:
    print(-1)    