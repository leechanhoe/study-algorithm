card = list(map(str, range(21)))
for _ in range(10):
    a, b = map(int, input().split())
    card = [0] + card[1:a] + card[b:a-1:-1] + card[b+1:]

print(" ".join(card[1:]))