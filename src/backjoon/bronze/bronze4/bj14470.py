a, b, c, d, e = [int(input()) for _ in range(5)]
ans = 0
ans += abs(min(a * c, 0))
ans += d if a < 0 else 0
ans += min(b * e, (b - a) * e)
print(ans)