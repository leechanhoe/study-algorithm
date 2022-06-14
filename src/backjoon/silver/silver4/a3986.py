cnt = 0
for i in range(int(input())):
    stk = []
    for ch in input():
        if stk and stk[-1] == ch:
            stk.pop()
            continue
        stk.append(ch)
    cnt += 0 if stk else 1

print(cnt)