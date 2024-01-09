s = input()
now = 'A'
ans = 0
for ch in s:
    dif = ord(now) - ord(ch)
    ans += min([abs(dif), abs(dif + 26), abs(dif - 26)])
    now = ch
print(ans)