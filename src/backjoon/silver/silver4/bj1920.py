N = int(input())
arr = [*map(int, input().split())]
arr.sort()
M = int(input())
arr2 = [*map(int, input().split())]

for i in arr2:
    s = 0
    e = N - 1
    ans = 0
    while s <= e:
        mid = (s + e) // 2
        if i >= arr[mid]:
            s = mid + 1
            ans = mid
        else:
            e = mid - 1
    if i == arr[ans]:
        print(1)
    else:
        print(0)