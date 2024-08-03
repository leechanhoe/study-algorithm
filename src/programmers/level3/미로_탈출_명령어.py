import sys
sys.setrecursionlimit(10 ** 7)

dir = [(1, 0, 'd'), (0, -1, 'l'), (0, 1, 'r'), (-1, 0, 'u')]
ans = "impossible"
def dfs(n, m, x, y, r, c, k, s):
    global ans

    if x == r and y == c and k == 0:
        ans = s
        return

    for dx, dy, ch in dir:
        nx = x + dx
        ny = y + dy
        if 0 < nx <= n and 0 < ny <= m and abs(nx - r) + abs(ny - c) <= k - 1:
            dfs(n, m, nx, ny, r, c, k - 1, s + ch)

        if ans != "impossible":
            return

def solution(n, m, x, y, r, c, k):
    if (abs(x - r) + abs(y - c)) % 2 != k % 2:
        return "impossible"

    dfs(n, m, x, y, r, c, k, "")
    return ans