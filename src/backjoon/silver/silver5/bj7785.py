import sys

input = sys.stdin.readline
s = set()

for _ in range(int(input())):
    name, state = input().split()
    if(state == "enter"):
        s.add(name)
    else:
        s.remove(name)

for name in sorted(s, reverse=True):
    print(name)