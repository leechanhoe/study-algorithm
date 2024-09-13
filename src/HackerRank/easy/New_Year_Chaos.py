#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
# 1 2 4 5 6 7 3

def minimumBribes(q):
    # Write your code here
    
    ans = 0
    for i, num in enumerate(q, start=1):
        if num - i >= 3:
            print("Too chaotic")
            return
        
        for j in range(max(num - 2, 0), i):
            if q[j] > num:
                ans += 1
            
    print(ans)
            

if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
