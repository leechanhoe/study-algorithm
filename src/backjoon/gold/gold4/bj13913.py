from collections import deque

def print_ans():
    temp = K
    ans = []
    while 1:
        ans.append(temp)
        if temp == N:
            print(len(ans) - 1)
            ans.reverse()
            print(*ans)
            exit(0)
        temp = chk[temp]

N, K = map(int, input().split())
chk = [-1] * 100001
dq = deque()
dq.append(N)
while dq:
    now = dq.popleft()
    for mv in [now - 1, now + 1, now * 2]:
        if 0 <= mv <= 100000 and chk[mv] < 0:
            chk[mv] = now
            if mv == K:
                print_ans()
            dq.append(mv)