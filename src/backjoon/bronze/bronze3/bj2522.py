N = int(input())

for i in range(1, N):
    for j in range(N-i):
        print(' ', end="")
    for j in range(i):
        print('*', end="")
    print()
    
for i in range(N):
    print('*', end="")
print()

for i in range(1, N):
    for j in range(i):
        print(' ', end="")
    for j in range(N-i):
        print('*', end="")
    print()