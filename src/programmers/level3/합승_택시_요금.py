def solution(n, s, a, b, fares):
    INF = 10e9
    dist = [[INF] * (n + 1) for _ in range(n + 1)]
    for c, d, f in fares:
        dist[c][d] = f
        dist[d][c] = f

    for k in range(1, n + 1):
        dist[k][k] = 0
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    ans = INF
    for i in range(1, n + 1):
        ans = min(ans, dist[s][i] + dist[i][a] + dist[i][b])

    return ans
