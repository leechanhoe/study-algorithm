import sys
from collections import deque
input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    p = input()
    n = int(input())
    x = deque(input()[1:-1].split(','))

    if n == 0:
        x = []

    error = rev = False
    for i in range(len(p)):
        if p[i] == 'R':
            rev = False if rev else True 
        else:
            if len(x) < 1:
                error = True
                print("error")
                break
            if rev:
                x.pop()
            else:
                x.popleft()
    
    if not error:
        if rev:
            x.reverse()
        print("[" + ",".join(x) + "]")