N = input()
F = int(input())

start = int(N[:-2] + '00')
end = start + 100
for i in range(start, end):
    if i % F == 0:
        print(str(i)[-2:])
        break