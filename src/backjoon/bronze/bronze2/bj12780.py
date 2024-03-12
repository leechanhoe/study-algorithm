H = input()
N = input()

cnt = 0
for i in range(len(H) - len(N) + 1):
    if H[i:i+len(N)] == N:
        cnt += 1

print(cnt)