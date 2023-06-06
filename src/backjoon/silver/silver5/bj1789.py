S = int(input())

tmp = 0
cnt = 0
for i in range(1, 100000000):
    tmp += i
    cnt += 1
    if tmp > S:
        cnt -= 1
        break
    elif tmp == S:
        break
print(cnt)