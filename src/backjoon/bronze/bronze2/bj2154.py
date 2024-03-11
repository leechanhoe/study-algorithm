s = ''
N = int(input())
for i in range(1, N + 1):
    s += str(i)

N = str(N)
l = len(N)
for i in range(len(s) - l + 1):
    if s[i:i+l] == N:
        print(i+1)
        break