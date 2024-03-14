K = int(input())
s = input()
for i in range(len(s)):
    if i % K == 0:
        print(s[i], end='')