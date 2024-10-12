# def solution(orders, course):
#     from collections import defaultdict
#     from itertools import combinations

#     answer = []

#     dic = defaultdict(int)
#     for o in orders:
#         for i in course:
#             for c in combinations(o, i):
#                 c = list(c)
#                 c.sort()
#                 dic["".join(c)] += 1

#     for i in course:
#         c = [b for a, b in dic.items() if len(a) == i and b > 1]
#         if not c:
#             continue
#         max_ = max(c)
#         tmp = [a for a, b in dic.items() if len(a) == i and b == max_]
#         answer += tmp
#     return sorted(answer)

import collections
import itertools


def solution(orders, course):
    result = []

    for course_size in course:
        order_combinations = []
        for order in orders:
            order_combinations += itertools.combinations(sorted(order), course_size)

        most_ordered = collections.Counter(order_combinations).most_common()
        result += [k for k, v in most_ordered if v > 1 and v == most_ordered[0][1]]

    return ["".join(v) for v in sorted(result)]
