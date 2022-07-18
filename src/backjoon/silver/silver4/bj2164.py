from collections import deque

dq = deque()

for i in range(int(input())):
    dq.append(i + 1)

while len(dq) > 1:
    dq.popleft()
    dq.append(dq.popleft())

print(dq.pop())