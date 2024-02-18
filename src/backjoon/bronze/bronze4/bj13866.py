abcd = list(map(int, input().split()))
sum_ = sum(abcd)
ans = 987654321
for i in range(4):
    for j in range(i + 1, 4):
        ans = min(ans, abs(sum_ - (abcd[i] + abcd[j]) * 2))
print(ans)