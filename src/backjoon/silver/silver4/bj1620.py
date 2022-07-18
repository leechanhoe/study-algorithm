import sys

input = sys.stdin.readline
N, M = map(int, input().split())

illustrated_book = dict()
for i in range(1, N + 1):
    a = input().strip()
    illustrated_book[a] = i
    illustrated_book[i] = a

for _ in range(M):
    inpu = input().strip()
    if inpu.isalpha():
        print(illustrated_book[inpu])
    else:
        print(illustrated_book[int(inpu)])