def solution(sequence, k):
    answer = []
    n = len(sequence)
    le = 0
    ri = 0
    now = sequence[0]
    min_size = 987654321
    while ri < n:
        if now < k:
            ri += 1
            if ri < n:
                now += sequence[ri]
        elif now > k:
            now -= sequence[le]
            le += 1
        elif now == k:
            if ri - le < min_size:
                answer = [le, ri]
                min_size = ri - le
            ri += 1
            if ri < n:
                now += sequence[ri]
            
    return answer