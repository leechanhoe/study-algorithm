N = int(input())
alpha = {}
words = []
for _ in range(N):
    words.append(input())

for word in words:
    for i, ch in enumerate(word):
        if ch in alpha:
            alpha[ch] += 10 ** (len(word) - i - 1)
        else:
            alpha[ch] = 10 ** (len(word) - i - 1)
            
num = 9
ans = 0
for i in sorted(list(alpha.values()), reverse=True):
    ans += num * i
    num -= 1
print(ans)