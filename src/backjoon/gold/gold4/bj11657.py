import sys
input = lambda : sys.stdin.readline().rstrip()
INF = 987654321

N, M = map(int, input().split())
edges = []
distance = [INF] * (N + 1)
for _ in range(M):
    edges.append(tuple(map(int, input().split())))

def bf(start):
    distance[start] = 0 # 시작 노드에 대해서 거리를 0으로 초기화
    for i in range(N): # 정점 수만큼 반복
        for j in range(M): # 매 반복 마다 모든 간선 확인
            now, next, cost = edges[j]
            # 현재 간선을 거려서 다른 노드로 이동하는 거리가 더 짧은 경우
            if distance[now] != INF and distance[next] > distance[now] + cost:
                if i == N - 1:
                    return True # n-1번 이후 반복에도 값이 갱신되면 음수 순환 존재
                distance[next] = distance[now] + cost
    return False

if bf(1):
    print(-1)
else:
    for i in range(2, N + 1):
        print(distance[i] if distance[i] != INF else -1)