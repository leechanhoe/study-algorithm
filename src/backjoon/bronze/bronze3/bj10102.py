N = int(input())
ab = input()
a = 0
b = 0
for ch in ab:
    if ch == 'A':
        a += 1
    else:
        b += 1

if a < b:
    print('B')
elif a > b:
    print('A')
else:
    print('Tie')