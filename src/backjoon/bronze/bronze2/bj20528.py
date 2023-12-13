N = int(input())
s = list(input().split())
ch = s[0][0]
for word in s:
    if word[0] != ch:
        print(0)
        exit(0)
print(1)