import sys
input = lambda : sys.stdin.readline().rstrip()

alpha = [[0, False] for i in range(10)] # 수, 맨앞자리에 온적있나
for _ in range(int(input())):
    s = input()[::-1]
    alpha[ord(s[-1]) - ord("A")][1] = True
    for i in range(len(s)):
        alpha[ord(s[i]) - ord("A")][0] += 10 ** i

alpha.sort()
if alpha[0][1]:
    for i in range(1, 10):
        if not alpha[i][1]:
            alpha[0], alpha[i] = alpha[i], alpha[0]
            break
alpha = [alpha[0]] + sorted(alpha[1:])

ans = 0
num = 9
for i in reversed(alpha):
    ans += i[0] * num
    num -= 1
print(ans)