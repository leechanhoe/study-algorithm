k = int(input())
sign = input().split()

mi = 10_000_000_000
ma = 0
visited = [False] * 10


def dfs(idx, now=""):
    global mi, ma

    if idx == k:
        mi = min(mi, int(now))
        ma = max(ma, int(now))
        return

    if idx == -1:
        for i in range(10):
            if not visited[i]:
                visited[i] = True
                dfs(idx + 1, str(i))
                visited[i] = False
    else:
        if sign[idx] == "<":
            for i in range(int(now[-1]) + 1, 10):
                if not visited[i]:
                    visited[i] = True
                    dfs(idx + 1, now + str(i))
                    visited[i] = False

        elif sign[idx] == ">":
            for i in range(int(now[-1])):
                if not visited[i]:
                    visited[i] = True
                    dfs(idx + 1, now + str(i))
                    visited[i] = False


dfs(-1)
print(str(ma).zfill(k + 1))
print(str(mi).zfill(k + 1))
