num = ""
ans = 0
is_minus = False

for ch in input():
    if ch.isdigit():
        num += ch
    else:
        ans += -int(num) if is_minus else int(num)
        num = ""
        if ch == '-':
            is_minus = True

ans += -int(num) if is_minus else int(num)
print(ans)