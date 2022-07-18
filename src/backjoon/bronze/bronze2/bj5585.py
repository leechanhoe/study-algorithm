n = 1000 - int(input())
coin_type = [500, 100, 50, 10, 5, 1]
count = 0

for i in coin_type:
    count += n // i
    n %= i
print(count)