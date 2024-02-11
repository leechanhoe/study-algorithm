a, b = map(int, input().split())
df = a - (a * b / 100)
if df >= 100:
    print(0)
else:
    print(1)