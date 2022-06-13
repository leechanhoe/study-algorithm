N = int(input())
dice = list(map(int, input().split()))
if N == 1:
    print(sum(dice) - max(dice))
else:
    ans = (((N - 2) ** 2) + (((N - 2) * (N - 1)) * 4)) * min(dice) # 보이는 면이 하나일결우

    mi2 = 1987654321
    for i in range(5):
        for j in range(i + 1, 6):
            if not j + i == 5:
                mi2 = min(mi2, dice[i] + dice[j])
    ans += (((N - 2) * 4) + ((N - 1) * 4)) * mi2 # 보이는 면이 2개

    ans += 4 * sum(min(dice[i], dice[-i - 1]) for i in range(3)) # 보이는 면이 3개 
    print(ans)