n = int(input())
seq = list(map(int, input().split()))
stk = []
ans = [-1] * n

for i in range(n): # 스택에 큰 수가 밑으로 가게 쌓는다
    while stk and seq[stk[-1]] < seq[i]: # 쌓을 수가 자리에 맞게 아래로 갈 때까지 작은 수들을 pop 해서 스택을 비운다
        ans[stk[-1]] = seq[i] # pop 한 자리는 쌓을 수가 오큰수가 된다.
        stk.pop()
    stk.append(i)

print(' '.join(map(str, ans)))