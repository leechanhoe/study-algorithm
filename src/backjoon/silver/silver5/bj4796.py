case = 0
while 1:
    L, P, V = map(int, input().split())
    if not L:
        break
    ans = (V // P) * L + min(L, V % P)
    case += 1
    print(f"Case {case}: {ans}")