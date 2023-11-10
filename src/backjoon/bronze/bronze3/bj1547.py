M = int(input())
cup = [0, 1, 2, 3]

for i in range(M):
    a, b = map(int, input().split())
    cup[a], cup[b] = cup[b], cup[a]

for i in range(1, 4):
    if cup[i] == 1:
        print(i)
        break