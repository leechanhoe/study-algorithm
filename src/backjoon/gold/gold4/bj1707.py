import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 6)

def dfs(start, group):
    global error

    # 만약 사이클이 true라면 재귀탈출
    if error:
        return

    visited[start] = group

    for i in graph[start]:
        if not visited[i]:
            dfs(i, -group) # 다른 그룹으로 설정
        elif visited[start] == visited[i]: # 인접한데 같은 그룹이면
            error = True
            return

for _ in range(int(input())):
    V, E = map(int, input().split())
    graph = [[] for _ in range(V + 1)]
    visited = [False] * (V + 1)
    error = False

    for _ in range(E):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    for i in range(1, V + 1):
        if not visited[i]:
            dfs(i, 1)
            if error: 
                break
    if error:
        print('NO')
    else:
        print('YES')