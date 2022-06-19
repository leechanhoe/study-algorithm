import sys

N, K = map(int, input().split())
thing = [[0, 0]]
d = [[0] * (K + 1) for _ in range(N + 1)]

for _ in range(N):
    thing.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(1, N + 1): # 이제까지 검사한 물건 개수
    w = thing[i][0]
    v = thing[i][1]
    for j in range(1, K + 1): # 무게마다 검사
        if j < w: # 못 넣을때 - 안넣음
            d[i][j] = d[i - 1][j]
        else: # 안넣었을때 : 자기무게를 빼고 넣었을 때 -> 더 큰것 선택
            d[i][j] = max(d[i - 1][j], d[i - 1][j - w] + v)

print(d[N][K])