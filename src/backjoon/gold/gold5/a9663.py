N = int(input())
check_col = [False] * N
check_dia1 = [False] * 2 * N ## /
check_dia2 = [False] * 2 * N ## \

cnt = 0
def put_queen(y):
    global cnt
    if(y >= N):
        cnt += 1
        return 

    for j in range(N if y else N // 2):
        if not check_col[j] and not check_dia1[y + j] and not check_dia2[y - j]:
            check_col[j] = True
            check_dia1[y + j] = True
            check_dia2[y - j] = True
            put_queen(y + 1)
            check_col[j] = False
            check_dia1[y + j] = False
            check_dia2[y - j] = False

if(N % 2):
    put_queen(0)
    cnt *= 2
    j = N // 2
    check_col[j] = check_dia1[j] = check_dia2[-j] = True
    put_queen(1)
    print(cnt)
else:
    put_queen(0)
    print(cnt * 2)