import sys
n = int(sys.stdin.readline())

for i in range(n):
    stack = []
    input = sys.stdin.readline()
    no = False

    for j in input:
        if(j =='('):
            stack.append(j)
        elif(j ==')'):
            if(len(stack) <= 0):
                no = True
                break
            stack.pop()

    if(len(stack) > 0 or no):
        print("NO")
    else:
        print("YES")