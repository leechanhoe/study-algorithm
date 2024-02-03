N = input()
ans = 0
for i in range(1, len(N)):
    ans += 9 * 10**(i - 1) * i
ans += (int(N) - 10**(len(N) - 1) + 1) * len(N)
print(ans) 