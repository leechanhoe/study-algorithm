import sys
input = sys.stdin.readline

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

for _ in range(int(input())):
    a, b = map(int, input().split())
    print(a * b // gcd(a, b))