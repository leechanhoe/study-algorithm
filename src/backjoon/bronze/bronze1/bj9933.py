N = int(input())
pwd = ""
words = {}
for i in range(N):
    word = input()
    if word == word[::-1] or word[::-1] in words.keys():
        pwd = word
    words[word] = True

print(len(pwd), pwd[len(pwd)//2])