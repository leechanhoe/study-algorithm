n = int(input())
first = list(input())
ans = 0

for i in range(n-1):
    diff = 0
    f = first[:]
    for ch in input():
        if ch in f:
            f.remove(ch)
        else:
            diff += 1
    if diff < 2 and len(f) < 2:
        ans += 1
print(ans)