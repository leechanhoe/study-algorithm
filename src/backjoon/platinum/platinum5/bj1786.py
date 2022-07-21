import sys
input = lambda : sys.stdin.readline().rstrip()

def maketable(p, kmp_table):
    j = 0
    for i in range(1, len(p)):
        while j > 0 and p[i] != p[j]: # 다르면 바로 이전(j-1) kmp 테이블로 간다
            j = kmp_table[j-1] # 가서 필요없는부분 점프한다
        if p[i] == p[j]:
            j += 1 # 같으면 i, j 를 1씩 늘려준다
            kmp_table[i] = j

def kmp(t, p, kmp_table):
    maketable(p, kmp_table)
    j = 0
    result = []
    p_size = len(p)
    for i in range(len(t)):
        while j > 0 and t[i] != p[j]:
            j = kmp_table[j-1]
        if t[i] == p[j]:
            if j == p_size - 1:
                result.append(i - p_size + 2)
                j = kmp_table[j]
            else:
                j += 1
    return result

T = input()
P = input()
kmp_table = [0] * len(P)
ans = kmp(T, P, kmp_table)
print(kmp_table)
print(len(ans))
print(*ans)