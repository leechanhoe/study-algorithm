#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    po = 0
    ne = 0
    ze = 0
    for i in arr:
        if i < 0:
            ne += 1
        elif i > 0:
            po += 1
        else:
            ze += 1
            
    print(f"{po / n:.6f}")
    print(f"{ne / n:.6f}")
    print(f"{ze / n:.6f}")
    # Write your code here

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
