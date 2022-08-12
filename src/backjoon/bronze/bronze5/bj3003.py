ans = [1, 1, 2, 2, 2, 8]
inpu = [*map(int, input().split())]
for i in range(6):
    print(ans[i] - inpu[i], end=" ")