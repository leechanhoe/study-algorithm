#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'balancedSums' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def balancedSums(arr):
    # Write your code here
    
    if len(arr) == 1:
        return "YES"
    
    s1 = 0
    s2 = sum(arr) - arr[0]
    for i in range(n - 1):
        if s1 == s2:
            print(i, s1)
            return "YES"
        s1 += arr[i]
        s2 -= arr[i+1]
        
    return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = balancedSums(arr)

        fptr.write(result + '\n')

    fptr.close()
