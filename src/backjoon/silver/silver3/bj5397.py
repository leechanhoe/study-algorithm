import sys

input = sys.stdin.readline
for _ in range(int(input())):
    typing = input().strip()
    stackl = []
    stackr = []

    for i in typing:
        if i == '<':
            if len(stackl):
                stackr.append(stackl.pop())
        elif i == '>':
            if len(stackr):
                stackl.append(stackr.pop())
        elif i == '-':
            if len(stackl):
                stackl.pop()
        else:
            stackl.append(i)

    print(''.join(stackl) + ''.join(reversed(stackr)))