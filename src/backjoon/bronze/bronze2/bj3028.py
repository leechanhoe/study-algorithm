cup = [0, 1, 0, 0]
suffle = input()
for s in suffle:
    if s == 'A':
        cup[1], cup[2] = cup[2], cup[1]
    elif s == 'C':
        cup[1], cup[3] = cup[3], cup[1]
    elif s == 'B':
        cup[2], cup[3] = cup[3], cup[2]

for i in range(1, 4):
    if cup[i]:
        print(i)