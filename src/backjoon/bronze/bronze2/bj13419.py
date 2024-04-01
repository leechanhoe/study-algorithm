T = int(input())
for _ in range(T):
    m = input()
    if len(m) % 2 == 0:
        print("".join(m[:-1:2]))
        print("".join(m[1::2]))
    else:
        print("".join(m[::2]) + "".join(m[1::2]))
        print("".join(m[1::2]) + "".join(m[::2]))