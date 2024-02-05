sum_, diff = map(int, input().split())
for a in range(1001):
    for b in range(1001):
        if a + b == sum_ and abs(a - b) == diff:
            print(max(a, b), min(a, b))
            exit(0)

print(-1)