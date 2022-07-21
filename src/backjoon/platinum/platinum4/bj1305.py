import sys

L = int(input())
s = sys.stdin.readline().rstrip()
kmp_table = [0] * L

j = 0
for i in range(1, L):
    while j > 0 and s[i] != s[j]:
        j = kmp_table[j-1]
    if s[j] == s[i]:
        j += 1
        kmp_table[i] = j

print(L - kmp_table[L-1])