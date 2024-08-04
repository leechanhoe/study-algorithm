import sys
sys.setrecursionlimit(10 ** 7)

def find(x, parent):
    if parent[x][0] != x:
        return find(parent[x][0], parent)
    return x

def uni(a, b, parent):
    a = find(a, parent)
    b = find(b, parent)

    if a < b:
        parent[b][0] = a
    else:
        parent[a][0] = b

    if parent[a][1] or parent[b][1]:
        parent[a][1] = True
        parent[b][1] = True

    if parent[a][2] or parent[b][2]:
        parent[a][2] = True
        parent[b][2] = True

def dfs(now, adj, is_gate, is_summit, visit, parent, max_w):
    visit[now] = True
    if is_gate[now]:
        return True

    is_ans = False
    for next, w in adj[now]:
        if not visit[next] and not is_summit[next] and w <= max_w:
            is_ans = dfs(next, adj, is_gate, is_summit, visit, parent, max_w)
            if is_ans:
                break

    return is_ans

def solution(n, paths, gates, summits):  
    parent = [[i, False, False] for i in range(n + 1)]

    is_gate = [False] * (n + 1)
    for gate in gates:
        is_gate[gate] = True
        parent[gate][1] = True

    is_summit = [False] * (n + 1)
    for summit in summits:
        is_summit[summit] = True
        parent[summit][2] = True

    max_w = 987654321
    ans_parent = []
    paths.sort(key=lambda x : x[2])

    for i, j, w in paths:
        if max_w < w:
            break
        fi = find(i, parent)
        fj = find(j, parent)
        if fi != fj:
            uni(i, j, parent)
            fj = find(j, parent)
            if parent[fj][1] and parent[fj][2]:
                max_w = w
                ans_parent.append(fj)

    adj = [[] for _ in range(n + 1)]
    for i, j, w in paths:
        adj[i].append((j, w))
        adj[j].append((i, w))

    ans_summit = 987654321
    for ap in ans_parent:
        visit = [False] * (n + 1)
        for i in range(1, n + 1):
            a = find(i, parent)
            if a == ap and is_summit[i]:
                if dfs(i, adj, is_gate, is_summit, visit, parent, max_w):
                    ans_summit = min(ans_summit, i)
                    break

    return [ans_summit, max_w]