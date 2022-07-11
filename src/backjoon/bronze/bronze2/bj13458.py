N = int(input())
A = [*map(int, input().split())]
B, C = map(int, input().split())

ans = N
for i in range(N):
    temp = A[i] - B
    if temp < 0:
        continue
    
    ans += temp // C
    if temp % C:
        ans += 1
print(ans)