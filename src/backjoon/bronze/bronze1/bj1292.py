arr = []
for i in range(1001):
    for j in range(i):
        arr.append(i)

a, b = map(int, input().split())
print(sum(arr[a-1:b]))