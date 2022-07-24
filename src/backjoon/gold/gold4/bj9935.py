import sys

s = sys.stdin.readline().rstrip()
b = sys.stdin.readline().rstrip()
stk = []
b_last = b[-1]
len_b = len(b)

for ch in s:
    stk.append(ch)
    if ch == b_last and ''.join(stk[-len_b:]) == b:
        del stk[-len_b:]

if stk:
    print(''.join(stk))
else:
    print("FRULA")