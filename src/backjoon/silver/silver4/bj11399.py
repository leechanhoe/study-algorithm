N = int(input())
P = sorted(list(map(int, input().split())))
ans = sum = 0

for i in P:
    sum += i
    ans += sum
print(ans)