N, L = map(int, input().split())
h = list(map(int, input().split()))
h.sort()

ans = L
for i in h:
    if i <= ans:
        ans += 1
    else:
        break

print(ans)