from collections import deque

ans = 987654321
N = int(input())
popul = [0] + list(map(int, input().split()))
adj = [[0]]
for _ in range(N):
    adj.append(list(map(int, input().split()[1:])))


def is_ok(li):
    visited2 = [False] * (N + 1)
    dq = deque()
    dq.append(li[0])
    visited2[li[0]] = True
    li2 = [li[0]]

    while dq:
        now = dq.pop()
        for next in adj[now]:
            if not visited2[next] and next in li:
                visited2[next] = True
                dq.appendleft(next)
                li2.append(next)

    return set(li) == set(li2)


def check(li):
    global ans, visited

    li2 = [i for i in range(1, N + 1) if not visited[i]]
    if is_ok(li) and is_ok(li2):
        dif = abs(sum([popul[i] for i in li]) - sum([popul[i] for i in li2]))
        ans = min(ans, dif)


def dfs(limit, now):
    global visited

    if limit == len(now):
        check(now)
        return

    start = 1 if not now else now[-1] + 1
    for i in range(start, N + 1):
        visited[i] = True
        now.append(i)
        dfs(limit, now)
        now.pop()
        visited[i] = False


for i in range(1, N):
    visited = [False] * (N + 1)
    dfs(i, [])

print(ans if ans != 987654321 else -1)
