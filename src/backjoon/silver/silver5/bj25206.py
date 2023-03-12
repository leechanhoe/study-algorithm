rate = ['A+', 'A0', 'B+', 'B0', 'C+', 'C0', 'D+', 'D0', 'F']
grade = [4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0]

total1 = 0
total2 = 0
for i in range(20):
    n, c, g = input().split()
    if g != "P":
        c = float(c)
        total1 += grade[rate.index(g)] * c
        total2 += c

print(total1 /total2)