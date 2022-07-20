import sys
input = lambda : sys.stdin.readline().rstrip()

def maketable(p, kmp_table):
    j = 0
    for i in range(1, len(p)):
        while j > 0 and p[i] != p[j]:
            j = kmp_table[j-1] # 다르면 이전의 맞은부분까지 가서 다시비교
        if p[i] == p[j]:
            j += 1
            kmp_table[i] = j

def kmp(t, p, kmp_table):
    maketable(p, kmp_table)
    j = 0
    cnt = 0
    result = []
    p_size = len(p)
    for i in range(len(t)):
        while j > 0 and t[i] != p[j]:
            j = kmp_table[j-1]
        if t[i] == p[j]:
            if j == p_size - 1:
                cnt += 1
                result.append(i - p_size + 2)
                j = kmp_table[j]
            else:
                j += 1
    return cnt, result

T = input()
P = input()
kmp_table = [0] * len(P)
cnt, loc = kmp(T, P, kmp_table)
print(cnt)
print(*loc)