cnt = [0] + [5] * 5
board = [list(map(int, input().split())) for _ in range(10)]
one = sum([sum(board[i]) for i in range(10)])
ans = 987654321

if one == 0:
    print(0)
    exit(0)
elif one == 100:
    print(4)
    exit(0)


def is_ok(r, c, size):
    global board

    if 10 < r + size or 10 < c + size:
        return False

    for i in range(r, r + size):
        for j in range(c, c + size):
            if board[i][j] == 0:
                return False

    return True


def trans(r, c, size, val):
    global board

    for i in range(r, r + size):
        for j in range(c, c + size):
            board[i][j] = val


def dfs(now):
    global one, ans, board, cnt
    if one == 0:
        ans = min(ans, now)
        return

    for i in range(10):
        for j in range(10):
            if board[i][j] == 1:
                for k in range(1, 6):
                    if is_ok(i, j, k):
                        if cnt[k]:
                            cnt[k] -= 1
                            trans(i, j, k, 0)
                            one -= k * k
                            dfs(now + 1)
                            one += k * k
                            trans(i, j, k, 1)
                            cnt[k] += 1
                    else:
                        break
                return


dfs(0)
print(ans if ans != 987654321 else -1)
