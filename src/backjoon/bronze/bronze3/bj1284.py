while 1:
    num = input()
    if num == '0':
        break
    ans = len(num) + 1
    for ch in num:
        if ch == '0':
            ans += 4
        elif ch == '1':
            ans += 2
        else:
            ans += 3
    print(ans)