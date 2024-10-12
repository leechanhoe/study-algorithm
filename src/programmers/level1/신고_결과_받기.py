def solution(id_list, report, k):
    from collections import defaultdict

    answer = []
    declared = defaultdict(int)
    user = defaultdict(set)
    for r in report:
        a, b = r.split()
        if b not in user[a]:
            declared[b] += 1
            user[a].add(b)

    for name in id_list:
        cnt = 0
        for d in user[name]:
            if declared[d] >= k:
                cnt += 1
        answer.append(cnt)

    return answer
