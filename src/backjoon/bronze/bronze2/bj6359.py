T = int(input())
for tc in range(T):
    n = int(input())
    open = [True] * (n + 1)
    for i in range(2, n + 1):
        for j in range(i, n + 1, i):
            open[j] = not open[j]

    print(sum(open) - 1)