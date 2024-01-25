li = ['Never gonna give you up'
,'Never gonna let you down'
,'Never gonna run around and desert you'
,'Never gonna make you cry'
,'Never gonna say goodbye'
,'Never gonna tell a lie and hurt you'
,'Never gonna stop']

N = int(input())
for i in range(N):
    s = input()
    if s not in li:
        print("Yes")
        exit(0)
print("No")