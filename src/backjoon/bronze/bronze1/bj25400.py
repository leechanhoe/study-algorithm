N = int(input())
A = list(map(int, input().split()))
now = 1
for card in A:
    if now == card:
        now += 1

print(N - now + 1)