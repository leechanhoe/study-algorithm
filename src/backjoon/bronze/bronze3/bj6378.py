while(1):
    num = input()
    if num == '0':
        break

    while(len(num) > 1):
        num = str(sum(map(int, list(num))))
    print(num)