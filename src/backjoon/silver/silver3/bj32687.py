A, B, K, M = map(int, input().split())
ans = 0
start = 10 ** (K - 1)
end = 10**K

for i in range(start, end):
    s = str(i)
    origin = s
    for j in range(13):
        num = int(s)
        if B < num:
            break
        if A <= num and num % M == 0:
            ans += 1

        s += origin[j % K]

print(ans)
