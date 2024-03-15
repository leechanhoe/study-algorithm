N = int(input())
word = [input() for _ in range(N)]
M = int(input())
candi = [input() for _ in range(M)]

def find_candi(s, e):
    if s == '':
        for c in candi:
            if c not in word and c[-1] == e:
                return c
    elif e == '':
        for c in candi:
            if c not in word and c[0] == s:
                return c
    else:
        for c in candi:
            if c not in word and c[-1] == e and c[0] == s:
                return c
            
for i in range(N):
    if word[i] == '?':
        if i == 0:
            print(find_candi('', word[i+1][0]))
        elif i == N-1:
            print(find_candi(word[i-1][-1], ''))
        else:
            print(find_candi(word[i-1][-1], word[i+1][0]))
        break    