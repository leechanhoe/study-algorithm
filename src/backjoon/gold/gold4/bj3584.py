import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    parents = [0] * (N + 1)
    for _ in range(N-1):
        p, c = map(int, input().split())
        parents[c] = p

    a, b = map(int, input().split())
    a_parent = [a]
    b_parent = [b]
    # 루트까지 탐색하며 경로저장
    while parents[a]:
        a_parent.append(parents[a])
        a = parents[a]

    while parents[b]:
        b_parent.append(parents[b])
        b = parents[b]

    a_level = len(a_parent) - 1
    b_level = len(b_parent) - 1
    # 루트부터 시작하여 공통 조상이 다를때까지 탐색
    while a_parent[a_level] == b_parent[b_level]:
        a_level -= 1
        b_level -= 1
    
    print(a_parent[a_level+1])