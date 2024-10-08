#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    ans = ""
    for ch in s:
        if ch.isalpha():
            if ord('a') <= ord(ch):
                ans += chr((ord(ch) - ord('a') + k) % 26 + ord('a'))
            else:
                ans += chr((ord(ch) - ord('A') + k) % 26 + ord('A'))
        else:
            ans += ch
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
