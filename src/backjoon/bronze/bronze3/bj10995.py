N = int(input())
for i in range(N):
    if i % 2:
        print(' ', end="")
    for i in range(N):
        print('* ', end="")
    print()