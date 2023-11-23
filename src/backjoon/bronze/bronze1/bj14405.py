pikachu = ["pi", "ka", "chu"]
s = input()
idx = 0

while idx < len(s):
    find = False
    for word in pikachu:
        if idx + len(word) <= len(s):
            if s[idx:idx + len(word)] == word:
                idx += len(word)
                find = True
                break

    if not find:
        print("NO")
        exit(0)
print("YES")