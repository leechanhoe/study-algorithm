R, C = map(int, input().split())
card = []
for i in range(R):
    row = input()
    row += row[::-1]
    card.append(row)
for i in range(R-1, -1, -1):
    card.append(card[i])

A, B = map(int, input().split())
ch = '#' if card[A-1][B-1] == '.' else '.'
tmp = list(card[A-1])
tmp[B-1] = ch
card[A-1] = ''.join(tmp)
for i in range(R * 2):
    print(card[i])