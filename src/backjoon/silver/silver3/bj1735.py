def getGcd(a, b):
    if(b == 0):
        return a
    return getGcd(b, a % b)

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

gcdB = getGcd(b1, b2)

b = b1 * b2 / gcdB
a = a1 * b2 / gcdB + a2 * b1 / gcdB

gcd2 = getGcd(a, b)
print(int(a / gcd2), int(b / gcd2))