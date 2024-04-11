ignore = ['i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili']
words = input().split()
ans = words[0][0].upper()

for i in range(1, len(words)):
    if words[i] not in ignore:
        ans += words[i][0].upper()

print(ans)