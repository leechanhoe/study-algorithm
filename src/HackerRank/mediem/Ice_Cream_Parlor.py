#!/bin/python3

import math
import os
import random
import re
import sys
from bisect import bisect_left, bisect_right

#
# Complete the 'icecreamParlor' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER m
#  2. INTEGER_ARRAY arr
#

def icecreamParlor(m, arr):
    arr2 = sorted(arr)
    for i in range(len(arr2)):
        x = m - arr2[i]
        le = bisect_left(arr2, x)
        ri = bisect_right(arr2, x)
        if le != ri:
            print(arr2[i], arr2[le])
            tmp = [arr2[i], arr2[le]]
            break
    
    ans = []
    if tmp[0] == tmp[1]:
        for i in range(len(arr)):
            if arr[i] == tmp[0] and not ans:
                ans.append(i + 1)
            elif arr[i] == tmp[1]:
                ans.append(i + 1)
    else:
        for i in range(len(arr)):
            if arr[i] == tmp[0]:
                ans.append(i + 1)
            elif arr[i] == tmp[1]:
                ans.append(i + 1)
    return sorted(ans)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        m = int(input().strip())

        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = icecreamParlor(m, arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
