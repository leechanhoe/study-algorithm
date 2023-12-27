T = int(input())
for _ in range(T):
    data = list(map(int, input().split()))
    even = []
    for num in data:
        if num % 2 == 0:
            even.append(num)
    print(sum(even), min(even))