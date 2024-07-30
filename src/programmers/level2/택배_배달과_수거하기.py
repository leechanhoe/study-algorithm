def solution(cap, n, deliveries, pickups):
    d = []
    p = []
    for i in range(n):
        if 0 < deliveries[i]:
            d.append([i + 1, deliveries[i]])
        if 0 < pickups[i]:
            p.append([i + 1, pickups[i]])
            
    ans = 0
    while d or p:
        left = cap
        d_max = 0
        if d:
            d_max = d[-1][0]
        ans += d_max
        while left and d:
            d_num = min(d[-1][1], left)
            left -= d_num
            d[-1][1] -= d_num
            if d[-1][1] <= 0:
                d.pop()
                
        left = cap
        p_max = 0
        if p:
            p_max = p[-1][0]
        ans += p_max + abs(d_max - p_max)
        while left and p:
            p_num = min(p[-1][1], left)
            left -= p_num
            p[-1][1] -= p_num
            if p[-1][1] <= 0:
                p.pop()
    return ans