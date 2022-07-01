N = int(input())
arr = [*map(int, input().split())]
lis = [arr[0]]

def binary_search(n):
    le = 0
    ri = len(lis) - 1
    while le <= ri:
        mi = (le + ri) // 2
        if lis[mi] == n:
            return mi
        elif lis[mi] < n:
            le = mi + 1
        else:
            ri = mi - 1
    return le

for num in arr:
    if num > lis[-1]:
        lis.append(num)
    elif num < lis[-1]:
        i = binary_search(num)
        lis[i] = num
print(len(lis))