from collections import Counter

for i in range(int(input())):
    s = input().split()
    c1 = Counter(s[0])
    c2 = Counter(s[1])

    print(f'{s[0]} & {s[1]} are ', end="")
    if c1 == c2:
        print("anagrams.")
    else:
        print("NOT anagrams.")