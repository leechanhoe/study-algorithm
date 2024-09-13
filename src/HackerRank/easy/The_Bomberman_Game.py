#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'bomberMan' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING_ARRAY grid
#

def bomberMan(n, grid):
    all_o = ['O' * c for _ in range(r)]
    other = [['O'] * c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 'O':
                for dr, dc in [(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1)]:
                    nr = i + dr
                    nc = j + dc
                    if 0 <= nr < r and 0 <= nc < c:
                        other[nr][nc] = '.'
    
    other2 = [['O'] * c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if other[i][j] == 'O':
                for dr, dc in [(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1)]:
                    nr = i + dr
                    nc = j + dc
                    if 0 <= nr < r and 0 <= nc < c:
                        other2[nr][nc] = '.'
                        
    for i in range(r):
        other[i] = "".join(other[i])
        other2[i] = "".join(other2[i])

    if n == 1:
        return grid
    if n % 4 == 1:
        return other2
    elif n % 4 == 3:
        return other
    else:
        return all_o
    
    # Write your code here
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    r = int(first_multiple_input[0])

    c = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    grid = []

    for _ in range(r):
        grid_item = input()
        grid.append(grid_item)

    result = bomberMan(n, grid)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
