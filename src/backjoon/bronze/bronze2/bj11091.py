N = int(input())
for _ in range(N):
    check = [0] * 26
    s = input().upper()
    for ch in s:
        if ord('A') <= ord(ch) <= ord('Z'):
            check[ord(ch) - ord('A')] = 1
    if sum(check) == 26:
        print("pangram")
    else:
        print('missing', end=" ")
        for i in range(26):
            if check[i] == 0:
                print(chr(ord('a')+i), end='')
        print()