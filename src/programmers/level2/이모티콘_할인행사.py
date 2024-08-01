from itertools import product
def solution(users, emoticons):
    n = len(users)
    m = len(emoticons)
    sale = [0.1, 0.2, 0.3, 0.4]
    all_combi = list(product(sale, repeat=m))
    users = [[x[0] * 0.01, x[1]] for x in users]
    ans = []

    for combi in all_combi:
        result = [0, 0]
        cost = [emoticons[i] * (1 - combi[i]) for i in range(m)]

        for i in range(n):
            user = 0
            for j in range(m):
                if users[i][0] <= combi[j]:
                    user += cost[j]

            if users[i][1] <= user:
                result[0] += 1
            else:
                result[1] += user

        ans.append(result[:])

    ans.sort()
    return ans[-1]