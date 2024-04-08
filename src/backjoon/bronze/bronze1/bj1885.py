K = int(input())
encode = input()

arr = []
for i in range(0, len(encode), K):
    arr.append(list(encode[i:i+K]))

for i in range(len(arr)):
    if i % 2 != 0:
        data = list(reversed(arr[i]))
        arr[i] = data

res = ''
for j in range(K):
    for i in range(len(arr)):
        res += arr[i][j]
print(res)