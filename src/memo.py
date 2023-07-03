from bisect import bisect_left, bisect_right

a = [1,3,5,5,7,9]
print(bisect_right(a, 5) - bisect_left(a, 5))