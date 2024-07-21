def solution(k, m, score):
    score.sort(reverse=True)
    s = 0
    e = m - 1
    answer = 0
    while e < len(score):
        answer += score[e] * m
        s += m
        e += m
    return answer