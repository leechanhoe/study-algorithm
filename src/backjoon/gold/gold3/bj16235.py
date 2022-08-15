import sys
from collections import deque

input = sys.stdin.readline

def spring_summer():
    for y in range(N):
        for x in range(N):
            for i in range(len(trees[y][x])):
                if trees[y][x][i] <= nut[y][x]:
                    nut[y][x] -= trees[y][x][i]
                    trees[y][x][i] += 1
                else:
                    for _ in range(len(trees[y][x]) - i):
                        nut[y][x] += trees[y][x].pop() // 2
                    break

def fall():
    for i in range(N):
        for j in range(N):
            breed = 0
            for age in trees[i][j]:
                if age % 5 == 0:
                    breed += 1

            if breed:
                for y in [-1, 0, 1]:
                    for x in [-1, 0, 1]:
                        if y == 0 and x == 0:
                            continue

                        ny = i + y
                        nx = j + x
                        if 0 <= ny < N and 0 <= nx < N:
                            for _ in range(breed):
                                trees[ny][nx].appendleft(1)

def winter():
    for i in range(N):
        for j in range(N):
            nut[i][j] += A[i][j]
    
N, M, K = map(int, input().split())
A = [[*map(int, input().split())] for _ in range(N)]
trees = [[deque() * N for _ in range(N)] for _ in range(N)]
for _ in range(M):
    c, r, age = map(int, input().split())
    trees[c-1][r-1].append(age)
nut = [[5] * N for _ in range(N)]

for _ in range(K):
    spring_summer()
    fall()
    winter()

ans = 0
for i in range(N):
    for j in range(N):
        ans += len(trees[i][j])
print(ans)