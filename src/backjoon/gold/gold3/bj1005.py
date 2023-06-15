import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())
for i in range(T):
    N, K = map(int, input().split())
    time = [0] + [*map(int, input().split())]
    indegree = [0] * (N + 1)

    adj = [list() for _ in range(N + 1)]
    for j in range(K):
        X, Y = map(int, input().split())
        adj[X].append(Y)
        indegree[Y] += 1
    W = int(input())

    zero = []
    for j in range(1, N + 1):
        if indegree[j] == 0:
            zero.append(j)
    
    prev = [0] * (N + 1)
    while zero:
        now = zero.pop()
        for next in adj[now]:
            indegree[next] -= 1
            prev[next] = max(prev[next], time[now] + prev[now])
            
            if indegree[next] == 0:
                zero.append(next)
    
    print(prev[W] + time[W])