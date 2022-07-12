a = input()
b = input()
cache = [0] * len(b)

for i in range(len(a)):
    ps = 0
    for j in range(len(b)):
        if ps < cache[j]:
            ps = cache[j]
        elif a[i] == b[j]:
            cache[j] = ps + 1
    print(cache)
print(max(cache))