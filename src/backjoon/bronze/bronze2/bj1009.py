tc = int(input())

for _ in range(tc):
    a, b = map(int, input().split())
    b = b % 4 + 4
    aa = a
    for i in range(b-1):
        aa = (aa * a) % 10
    if aa == 0:
        print(10)
    else:
        print(aa)