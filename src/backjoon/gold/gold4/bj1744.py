N = int(input())
pos = []
neg = []
zero = []
for _ in range(N):
    num = int(input())
    if num > 0:
        pos.append(num)
    elif num < 0:
        neg.append(num)
    else:
        zero.append(num)
pos.sort()
neg.sort(reverse=True)

ans = 0
while 1:
    if len(pos) > 1: # 양수가 2개면 
        a = pos.pop()
        b = pos.pop()
        if a > 1 and b > 1: # 1이 아니면 곱
            ans += a * b
        else: # 1이 있으면 더하는게 더 큼
            ans += a + b
    elif len(neg) > 1: # 음수가 2개면 곱하면 양수
        ans += neg.pop() * neg.pop()
    elif neg and zero: # 음수 1개 0이 1개면 음수를 없앰
        ans += neg.pop() * zero.pop()
    else: # 더 합칠게 없으면 스탑
        break
print(ans + sum(pos) + sum(neg))