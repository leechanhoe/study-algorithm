def gcd(a, b):
    while b:
        if a > b:
            a, b = b, a
        b %= a
    return a

T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    gcd_ = gcd(a, b)
    print(a * b // gcd_, gcd_)