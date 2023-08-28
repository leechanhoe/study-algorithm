import sys
import queue
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
qs = [*map(int, input().split())]
val = list(map(int, input().split()))
M = int(input())
ins = list(map(int, input().split()))

q = queue.Queue()
for i in range(N - 1, -1, -1):
    if qs[i] == 0:
        q.put(val[i])

for i in range(M):
    q.put(ins[i])
    print(q.get(), end=' ')