a, b = map(int, input().split())

dx = abs((a - 1) % 4 - (b - 1) % 4)
dy = abs((a - 1) // 4 - (b - 1) // 4)
print(dx + dy)