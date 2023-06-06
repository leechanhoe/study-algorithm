T = int(input())
if T % 10 != 0:
    print(-1)
    exit(0)
    
a = b = c = 0

while T - 300 >= 0:
    T -= 300
    a += 1

while T - 60 >= 0:
    T -= 60
    b += 1

while T - 10 >= 0:
    T -= 10
    c += 1

print(a, b, c)
