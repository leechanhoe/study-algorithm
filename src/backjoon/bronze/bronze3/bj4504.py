n = int(input())
while 1:
    num = int(input())
    if num == 0:
        break

    if num % n == 0:
        print(f"{num} is a multiple of {n}.")
    else:
        print(f"{num} is NOT a multiple of {n}.")