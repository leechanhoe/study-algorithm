import sys
input = lambda : sys.stdin.readline().rstrip()

V, E = map(int, input().split())
parent = list(range(V + 1)) # 부모를 자기 자신으로 초기화

#특정 원소가 속한 집합 찾기
def find(x):
    #루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀호출
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

# 두 원소가 속한 집합을 합치기
def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parent[b] = a
    else:
        parent[a] = b

edge = []
for _ in range(E):
    a, b, c = map(int, input().split())
    edge.append((a, b, c))
edge.sort(key=lambda x : x[2]) # 가중치 순으로 정렬

ans = 0
for a, b, c in edge:
    if find(a) != find(b): # 사이클이 발생하지 않는 경우
        union(a, b)
        ans += c
print(ans)