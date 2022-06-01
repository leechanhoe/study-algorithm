import sys

input = sys.stdin.readline
s = set()

for _ in range(int(input())):
    inpu = input().strip().split()
    command = inpu[0]
    if len(inpu) == 1:
        if command == 'all':
            s = set(x for x in range(1, 21))
        else:
            s = set()

    else:
        val = int(inpu[1])
        if command == "add":
            s.add(val)
        elif command == 'remove':
            s.discard(val)
        elif command == 'check':
            print(1 if val in s else 0)
        elif command == 'toggle':
            if val in s:
                s.discard(val)
            else:
                s.add(val)