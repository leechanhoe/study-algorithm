import math

def dq(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    
    log = int(math.log2(n))
    if 2 ** log == n:
        return 1 if log % 2 else 0
    return 1 - dq(n - 2 ** log)

k = int(input())
print(dq(k))

# n = int(input())

# n -= 1
# count = 0
# while n:
#   if (n%2):
#     count += 1
#   n //= 2

# print(count%2)