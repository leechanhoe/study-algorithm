# from collections import deque

# dq = deque()
# N = int(input())
# for _ in range(N):
#     cmd = input()
#     if 3 == len(cmd):
#         cmd, x = map(int, cmd.split())
#     elif 1 == len(cmd):
#         cmd = int(cmd)
    
#     if cmd == 1:
#         dq.appendleft(x)
#     elif cmd == 2:
#         dq.append(x)
#     elif cmd == 3:
#         if 0 < len(dq):
#             print(dq.popleft())
#         else:
#             print(-1)
#     elif cmd == 4:
#         if 0 < len(dq):
#             print(dq.pop())
#         else:
#             print(-1)
#     elif cmd == 5:
#         print(len(dq))
#     elif cmd == 6:
#         if 0 < len(dq):
#             print(0)
#         else:
#             print(1)
#     elif cmd == 7:
#         if 0 < len(dq):
#             print(dq[0])
#         else:
#             print(-1)
#     elif cmd == 8:
#         if 0 < len(dq):
#             print(dq[-1])
#         else:
#             print(-1)

import sys
from collections import deque
n=int(input())
d=deque()
for i in range(n):
    l=list(map(int,sys.stdin.readline().strip().split()))
    t=l[0]
    f=len(d)
    if t==1:
        d.appendleft(l[1])
    elif t==2:
        d.append(l[1])
    elif t==3:
        print(d.popleft() if f else -1)
    elif t==4:
        print(d.pop() if f else -1)
    elif t==5:
        print(len(d))
    elif t==6:
        print(0 if f else 1)
    elif t==7:
        print(d[0] if f else -1)
    elif t==8:
        print(d[-1] if f else -1)