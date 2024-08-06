def solution(alp, cop, problems):
    maxa = 0
    maxc = 0
    for p in problems:
        maxa = max(maxa, p[0])
        maxc = max(maxc, p[1])
        
    dp = [[0] * 151 for a in range(151)]

    alp = min(alp, maxa)
    cop = min(cop, maxc)
    for a in range(alp, maxa + 1):
        for c in range(cop, maxc + 1):
            dp[a][c] = (a - alp) + (c - cop)
    
    for a in range(alp, maxa + 1):
        for c in range(cop, maxc + 1):
            for alp_req, cop_req, alp_rwd, cop_rwd, cost in problems:
                na = min(a + alp_rwd, maxa)
                nc = min(c + cop_rwd, maxc)
                if alp_req <= a and cop_req <= c:
                    dp[na][nc] = min(dp[na][nc], dp[a][c] + cost)
                
    return dp[maxa][maxc]