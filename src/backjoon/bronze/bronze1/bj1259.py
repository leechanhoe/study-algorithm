while 1:
    a = input()
    no = False
    if(a == '0'):
        break

    for i in range(round(len(a) / float(2))):
        if(a[i] != a[-1 - i]):
            print("no")
            no = True
            break
    if(no == False):
        print("yes")