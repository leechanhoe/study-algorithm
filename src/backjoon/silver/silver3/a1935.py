n = int(input())
stk = []
val = []
notation = input().strip()
for i in range(n):
    val.append(float(input()))

for i in notation:
    if(i == '*'):
        stk.append(stk.pop() * stk.pop())
    elif(i == '+'):
        stk.append(stk.pop() + stk.pop())
    elif(i == '-'):
        stk.append(stk.pop(len(stk) - 2) - stk.pop())
    elif(i == '/'):
        stk.append(stk.pop(len(stk) - 2) / stk.pop())
    else:
        stk.append(val[ord(i) - ord('A')])

print(f'{stk[0]:.2f}')