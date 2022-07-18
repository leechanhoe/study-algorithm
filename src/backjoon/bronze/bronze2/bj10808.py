a = input()
cnt = [0] * 26

for i in a:
    cnt[ord(i) - ord('a')] += 1

print(*cnt)