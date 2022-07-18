n, k= map(int, input().split(' '))
cir = [i for i in range(1,n + 1)]
index = 0
ans = []
while cir:
    index += k - 1
    index %= len(cir)
    ans.append(cir.pop(index))
print(f"<{', '.join(map(str, ans))}>")