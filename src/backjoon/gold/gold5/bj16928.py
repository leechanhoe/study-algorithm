from collections import deque

N, M = map(int, input().split())
board = [0] * 101
visit = [False] * 101
for _ in range(N):
    x, y = map(int, input().split())
    board[x] = y
for _ in range(M):
    u, v = map(int, input().split())
    board[u] = v
dice = (1, 2, 3, 4, 5, 6)

dq = deque()
dq.append((1, 0))

ans = 0
while dq:
    loc, cnt = dq.popleft()
    if loc == 100:
        ans = cnt
        break
    for num in dice:
        nloc = loc + num
        if nloc <= 100 and not visit[nloc]:
            if board[nloc]:
                dq.append((board[nloc], cnt + 1))
                visit[nloc] = True
            else:
                dq.append((nloc, cnt + 1))
                visit[nloc] = True
print(cnt)