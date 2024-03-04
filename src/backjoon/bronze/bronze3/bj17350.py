N = int(input())
names = [input() for _ in range(N)]
for name in names:
    if name == 'anj':
        print('뭐야;')
        exit(0)
print('뭐야?')