s = input()

a = b = 0
for ch in s:
    if ch == ':':
        a += 1
    elif ch == '_':
        b += 1

print(len(s) + a + b * 5)