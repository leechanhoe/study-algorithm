from collections import deque

q = int(input())
dq = deque()

for _ in range(q):
    typ = list(map(int, input().split()))
    
    if typ[0] == 1:
        dq.append(typ[1])
    elif typ[0] == 2:
        dq.popleft()
    else:
        print(dq[0])