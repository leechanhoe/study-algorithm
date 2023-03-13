N = int(input())

le, ri = input().split('*')
for i in range(N):
    p = input()
    if len(le) + len(ri) > len(p):
        print("NE")
        continue

    if le == p[:len(le)] and ri == p[len(p)-len(ri):]:
        print("DA")
    else:
        print("NE")