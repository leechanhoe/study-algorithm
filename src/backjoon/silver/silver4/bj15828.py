import sys
import queue
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
q = queue.Queue()
while 1:
    num = int(input())
    if num == 0:
        q.get()
    elif num == -1:
        break
    else:
        if q.qsize() < N:
            q.put(num)

if q.empty():
    print("empty")
else:
    while not q.empty():
        print(q.get())