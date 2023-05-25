abc = sorted(map(int, input().split()))
ans = abc[0] + abc[1] + min(abc[0] + abc[1] - 1, abc[2])
print(ans)