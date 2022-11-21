import sys

while True:
    line = sys.stdin.readline().rstrip('\n')
    if not line:
        break

    l = u = d = s = 0
    for ch in line:
        if ch.islower():
            l += 1
        elif ch.isupper():
            u += 1
        elif ch.isdigit():
            d += 1
        elif ch.isspace():
            s += 1
    print(l, u, d, s)