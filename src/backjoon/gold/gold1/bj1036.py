import sys
import itertools
input = lambda : sys.stdin.readline().rstrip()

def to36(n):
    li = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    a, b = divmod(n, 36)
    ch = li[b]
    return to36(a) + ch if a != 0 else ch

N = int(input())
cnt = {}
for ch in "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    cnt[ch] = 0
words = [input() for _ in range(N)]
K = int(input())

for word in words:
    for i in range(len(word)):
        cnt[word[::-1][i]] += 36 ** i

for ch in cnt.keys():
    cnt[ch] = cnt[ch] * (35 - int(ch, 36))

cnt = sorted(cnt.items())
cnt.sort(key=lambda x : x[1], reverse=True)

for ch in cnt[:K]:
    for i in range(len(words)):
        words[i] = words[i].replace(ch[0], "Z")

ans = 0
for word in words:
    ans += int(word, 36)

print(to36(ans))