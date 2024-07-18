board = [[0] * 8 for _ in range(8)]
king, stone, N = input().split()
ky = 8 - int(king[1])
kx = ord(king[0]) - ord('A')
sy = 8 - int(stone[1])
sx = ord(stone[0]) - ord('A')

move = {'R':[0, 1], 'L':[0, -1], 'B':[1, 0], 'T':[-1, 0], 
        'RT':[-1, 1], 'LT':[-1, -1], 'RB':[1, 1], 'LB':[1, -1]}
for _ in range(int(N)):
    mv = input()
    nky = move[mv][0] + ky
    nkx = move[mv][1] + kx
    if 0 <= nky < 8 and 0 <= nkx < 8:
        nsy = sy
        nsx = sx
        if nky == sy and nkx == sx:
            nsy = move[mv][0] + sy
            nsx = move[mv][1] + sx
            if not (0 <= nsy < 8 and 0 <= nsx < 8):
                continue

        ky = nky
        kx = nkx
        sy = nsy
        sx = nsx

print(chr(kx + ord('A')) + str(8 - ky))
print(chr(sx + ord('A')) + str(8 - sy))