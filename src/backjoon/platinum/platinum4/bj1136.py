INF = 1987654321
cache = [INF] * 10000000
A, B, K = map(int, input().split())

def S(n):
    return sum(int(ch) ** K for ch in str(n))

def dfs(n):
    if cache[n] == INF: # 한번도 방문하지 않은 곳
        cache[n] = 0 # 임시 방문체크
        cache[n] = min(n, dfs(S(n)))

    elif not cache[n]: # 임시 방문체크한곳을 만남
        cycle = [n]
        mi = n
        nn = S(n)
        
        while nn != n: # 다시 사이클을 돌면서 사이클 값들이랑 최솟값찾고
            mi = min(mi, nn)
            cycle.append(nn)
            nn = S(nn)

        for i in cycle: # 사이클들에 최솟값 넣기
            cache[i] = mi
    return cache[n]

print(sum(dfs(i) for i in range(A, B + 1)))