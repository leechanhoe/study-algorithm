mi = 100
su = 0
for i in range(7):
    n = int(input())
    if n % 2 == 1:
        mi = min(mi, n)
        su += n
if su == 0:
    print(-1)
else:
    print(su)
    print(mi)