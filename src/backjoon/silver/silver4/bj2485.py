import sys
input = lambda : sys.stdin.readline().rstrip()

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

N = int(input())
prev = int(input())
first = prev
diff = []
for i in range(N - 1):
    tree = int(input())
    diff.append(tree - prev)
    prev = tree

g = diff[0]
for i in range(1, N - 1):
    g = gcd(g, diff[i])

print((prev - first) // g - N + 1)