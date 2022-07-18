import sys
input = lambda : sys.stdin.readline().rstrip()
INF = 987654321

N = int(input())
M = int(input())
   # [최단거리, 경로]
graph =[[[INF, []] for __ in range(N + 1)] for _ in range(N + 1)] # 무한으로 초기화
for _ in range(M):
    a, b, c = map(int, input().split())
    if graph[a][b][0] > c:
        graph[a][b][0] = c
        graph[a][b][1] = [a, b]

for k in range(1, N + 1):
    for a in range(1, N + 1):
        for b in range(1, N + 1): # 최단 기록 테이블의 A->B비용과 A->K->B 비용 중 작은 것을 기록 
            if graph[a][b][0] > graph[a][k][0] + graph[k][b][0]:
                graph[a][b][0] = graph[a][k][0] + graph[k][b][0]
                graph[a][b][1] = graph[a][k][1] + graph[k][b][1][1:]

for a in range(N + 1):
    for b in range(N + 1):
        if a == b or graph[a][b][0] == INF:
            graph[a][b][0] = 0
            graph[a][b][1] = []

for i in range(1, N + 1):
    for j in range(1, N + 1):
        print(graph[i][j][0], end=" ")
    print()
for i in range(1, N + 1):
    for j in range(1, N + 1):
        print(len(graph[i][j][1]), *graph[i][j][1])