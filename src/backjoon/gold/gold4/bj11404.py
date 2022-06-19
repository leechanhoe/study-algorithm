import sys
input = lambda : sys.stdin.readline().rstrip()
INF = 987654321

N = int(input())
M = int(input())
graph =[[INF] * (N + 1) for _ in range(N + 1)] # 무한으로 초기화
for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)

for k in range(1, N + 1):
    for a in range(1, N + 1):
        for b in range(1, N + 1): # 최단 기록 테이블의 A->B비용과 A->K->B 비용 중 작은 것을 기록 
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(N + 1):
    for b in range(N + 1):
        if a == b or graph[a][b] == INF:
            graph[a][b] = 0

for i in range(1, N + 1):
    print(*graph[i][1:])