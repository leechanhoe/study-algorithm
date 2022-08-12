import sys
from collections import deque
input = sys.stdin.readline

def dslr(n):
    ret = []
    d = n * 2
    ret.append((d, 'D') if d <= 9999 else (d % 10000, 'D'))
    ret.append((n - 1, 'S') if n > 0 else (9999, 'S'))
    strn = str(n + 10000)[1:]
    l = strn[1:] + strn[0]
    r = strn[-1] + strn[:-1]
    ret.append((int(l), 'L'))
    ret.append((int(r), 'R'))
    return ret

def bfs(a, b):
    dq = deque()
    dq.append([a,[]])
    chk = [False] * 10000

    while dq:
        n, com = dq.popleft()
        for val, oper in dslr(n):
            if not chk[val]:
                ncom = com + [oper]
                chk[val] = True
                if val == b:
                    print(''.join(ncom))
                    return
                dq.append((val, ncom))

for _ in range(int(input())):
    a, b = map(int, input().split())
    bfs(a, b)