N = int(input())
arr = input()
if len(arr) > 1:
    arr = [*map(int, arr.split())]
else:
    arr = [int(arr[0])]
print(min(arr) * max(arr))