dish = input()
ans = 10

for i in range(1, len(dish)):
    if dish[i] == dish[i-1]:
        ans += 5
    else:
        ans += 10

print(ans)