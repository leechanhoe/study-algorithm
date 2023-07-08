a, b, d, N = map(int, input().split())

birth = [0] * (N + d) # i일에 태어난애들
birth[0] = 1
num = [0] * (N + d) # i일의 총 개체 수
num[0] = 1
pro = [0] * (N + d) # i일의 생산능력
for i in range(1, N + 1):
    num[i] = num[i-1]
    pro[i] = pro[i-1]
    if i >= a:
        pro[i] += birth[i-a]
    if i >= b:
        pro[i] -= birth[i-b]
    if i >= d:
        num[i] -= birth[i-d]
    num[i] += pro[i]
    birth[i] = pro[i]

    num[i] %= 1000
    birth[i] %= 1000
    pro[i] %= 1000

print(num[N])
