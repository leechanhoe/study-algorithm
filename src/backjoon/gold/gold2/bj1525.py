from collections import deque
from copy import deepcopy

def convert(board):
    ret = 0
    for i in range(9):
        ret += board[i] * (9 ** i)
    return ret

board = []
for i in range(3):
    board += list(map(int, input().split()))
dq = deque()
dq.append([board, board.index(0), 0])
visit = {}
visit[convert(board)] = True

while dq:
    now, blank, n = dq.popleft()
    if now == [1,2,3,4,5,6,7,8,0]:
        print(n)
        exit(0)

    y = blank // 3
    x = blank % 3
    for dir in [(0, 1, 1), (0, -1, -1), (1, 0, 3), (-1, 0, -3)]:
        ny = y + dir[0]
        nx = x + dir[1]
        if 0 <= ny < 3 and 0 <= nx < 3:
            next = deepcopy(now)
            next[blank], next[blank + dir[2]] = next[blank + dir[2]], next[blank]
            conv = convert(next)
            if conv not in visit:
                visit[conv] = True
                dq.append([next, blank + dir[2], n + 1])
print(-1)