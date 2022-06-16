import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
h = []
for _ in range(N):
    h.append(list(map(int, input().split())))

for i in range(1, N):
    h[i][0] += min(h[i - 1][1], h[i - 1][2])
    h[i][1] += min(h[i - 1][0], h[i - 1][2])
    h[i][2] += min(h[i - 1][0], h[i - 1][1])
print(min(h[N - 1]))