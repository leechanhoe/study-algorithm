import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
M = int(input())
s = input()
ans = 0
p = 0
dp = [0] * 14
for i in range(M-2):
    if s[i] == 'I':
        if s[i:i+3] == 'IOI':
            p += 1
            if p == N:
                ans += 1
                p -=1
        else:
            p = 0
print(ans)