import math


def lcm(a, b):
    # 최대공약수 (GCD)를 구한 뒤, LCM을 계산
    return (a * b) // math.gcd(a, b)


a, b = map(int, input().split())

# 최소공배수 계산
result = lcm(a, b)

print(result)
