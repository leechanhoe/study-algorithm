x = input()
ans = 0
while len(x) > 1:
    total = 0
    for i in x:
        total += int(i)
    x = str(total)
    ans += 1

print(ans)
if int(x) % 3 == 0:
    print("YES")
else:
    print("NO")
