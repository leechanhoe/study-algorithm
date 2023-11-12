N = int(input())
car = list(map(int, input().split()))
ans = 0
for i in car:
    if N == i:
        ans += 1

print(ans)