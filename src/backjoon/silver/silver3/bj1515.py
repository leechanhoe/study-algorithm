N = input()
tmp = ""

for i in range(1, 1000000):
    for ch in str(i):
        if N[len(tmp)] == ch:
            tmp += ch
            if len(tmp) == len(N):
                print(i)
                exit(0)