import sys
s = sys.stdin.readline().rstrip()

stk = []
inTag = False
ans = ""
for ch in s:
    if ch == '<':
        inTag = True
        while stk:
            ans += stk.pop()
        ans += ch
    elif ch == '>':
        inTag = False
        ans += ch
    elif not inTag and ch != ' ':
        stk.append(ch)
    elif not inTag and ch == ' ':
        while stk:
            ans += stk.pop()
        ans += ch
    else:
        ans += ch

while stk:
    ans += stk.pop()
print(ans)