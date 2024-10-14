while 1:
    try:
        s, t = input().split()
        j = 0
        for i in range(len(t)):
            if s[j] == t[i]:
                j += 1
                if j == len(s):
                    break

        if j == len(s):
            print("Yes")
        else:
            print("No")
    except:
        break
