import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
ans = 0
stk = []

for _ in range(N):
    inpu = input()
    
    if inpu[0] == '1':
        _, a, t = map(int, inpu.split())
        stk.append([a, t])

    if not stk:
        continue

    stk[-1][1] = stk[-1][1] - 1
    if stk[-1][1] == 0:
        ans += stk[-1][0]
        stk.pop()

print(ans)