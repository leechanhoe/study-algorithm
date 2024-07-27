import itertools
from bisect import bisect_left

def solution(dice):
    n = len(dice)
    high = 0
    answer = []

    combinations_of_dice = itertools.combinations(dice, n // 2)
    for combination in combinations_of_dice:
        remaining_combination = [item for item in dice if item not in combination]
        product_comb = itertools.product(*combination)
        a_sums = sorted([sum(c) for c in product_comb])
        product_comb = itertools.product(*remaining_combination)
        b_sums = sorted([sum(c) for c in product_comb])

        win = 0
        for s in a_sums:
            win += bisect_left(b_sums, s)
        if win > high:
            high = win
            answer = combination
        high = max(high, win)

    ans = []
    for i in range(n):
        for j in range(n // 2):
            if dice[i] == answer[j]:
                ans.append(i+1)
                break

    return ans