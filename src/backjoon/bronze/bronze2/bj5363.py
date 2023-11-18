N = int(input())
for i in range(N):
    s = input().split()
    print(" ".join(s[2:]), " ".join(s[:2]))