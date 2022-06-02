def b():
    a = list(map(int, input().split()))
    for i in range(len(a) - 1):
        if abs(a[i] - a[i + 1]) > 1:
            print("mixed")
            return
    print("ascending") if a[7] - a[0] == 7 else print("descending")
b()