from math import log2
import sys
sys.setrecursionlimit(10 ** 7)

def check(b, i, depth):
    if depth == 0:
        return True

    elif b[i] == '0':
        if b[i - depth] == '1' or b[i + depth] == '1':
            return False

    le = check(b, i - depth, depth // 2)
    ri = check(b, i + depth, depth // 2)
    return le and ri

def solution(numbers):
    ans = []
    for n in numbers:
        bi = bin(n)[2:]
        num_len = 2 ** (int(log2(len(bi))) + 1) - 1
        num = '0' * (num_len - len(bi)) + bi
        if check(num, len(num) // 2, (len(num) + 1) // 4):
            ans.append(1)
        else:
            ans.append(0)

    return ans
