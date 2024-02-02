while(1):
    s = input()
    if s == "#":
        break
    
    check = [0] * 26
    for ch in s.lower():
        if ch.isalpha():
            check[ord(ch)-97] = 1
    
    print(sum(check))