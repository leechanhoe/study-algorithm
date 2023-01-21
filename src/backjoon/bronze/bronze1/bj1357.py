def rev(s):
    return int(str(s)[::-1])

x, y = input().split()
print(rev(rev(x) + rev(y)))