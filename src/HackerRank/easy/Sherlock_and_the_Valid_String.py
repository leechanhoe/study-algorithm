#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter
from collections import defaultdict

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    cnt = Counter(s)
    dic = defaultdict(list)
    for k, v in cnt.items():
        dic[v].append(k)
        
    if 2 < len(dic):
        print("2more dic:", dic)
        return "NO"
    elif 1 == len(dic):
        print("1 dic:", dic)
        return "YES"
    else:
        key = sorted(list(dic.keys()))
        if key[0] == 1 and len(dic[key[0]]) == 1:
            return "YES"
            
        if key[1] - key[0] != 1:
            print(key)
            return "NO"
            
        value = list(dic.values())
        if len(value[0]) == 1 or len(value[1]) == 1:
            return "YES"
    return "NO"
        
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
