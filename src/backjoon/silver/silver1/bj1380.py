tc = 1
while(1):
    n = int(input())
    if n == 0:
        break

    check = [False] * (n + 1)
    name = {}
    for i in range(1, n + 1):
        name[i] = input()

    for i in range(2 * n - 1):
        a, b = input().split()
        a = int(a)
        check[a] = not check[a]
    
    for i in range(1, n + 1):
        if check[i]:
            print(tc, name[i])
            break
        
    tc += 1