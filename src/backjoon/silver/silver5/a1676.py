from math import factorial

cnt = 0
for ch in reversed(str(factorial(int(input())))):
    if ch == '0':
        cnt += 1
    else:
        break
print(cnt)