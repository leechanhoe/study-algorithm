import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())

stk = []
for _ in range(N):
    cmd = input().split()

    if cmd[0] == '1':
        stk.append(cmd[1])
    elif cmd[0] == '2':
        print(stk.pop() if stk else -1)
    elif cmd[0] == '3':
        print(len(stk))
    elif cmd[0] == '4':
        print(0 if stk else 1)
    elif cmd[0] == '5':
        print(stk[-1] if stk else -1)
