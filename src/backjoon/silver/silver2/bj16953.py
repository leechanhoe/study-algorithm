A, B = map(int,input().split())
ans = 1
while(B != A):
    ans += 1
    temp = B
    if B % 10 == 1:
        B //= 10
    elif B % 2 == 0:
        B //= 2
    
    if temp == B:
        ans = -1
        break
print(ans)