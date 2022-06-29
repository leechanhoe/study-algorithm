from collections import deque
import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
indegree = [0] * (N + 1) # 진입 차수
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

result = []
dq = deque()
for i in range(1, N + 1):
    if indegree[i] == 0: # 진입차수가 0인 노드 큐에 넣기
        dq.append(i)

while dq:
    now = dq.popleft()
    result.append(now)
    for i in graph[now]:
        indegree[i] -= 1 # 해당 원소와 연결된 노드들 진입차수 1 빼기
        if indegree[i] == 0: # 진입차수가 0이면 또 넣기
            dq.append(i)

print(*result)