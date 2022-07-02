N = int(input())
arr = [*map(int, input().split())]
inc = [1] * N
dec = [1] * N
for i in range(N):
    for j in range(i):
        if arr[i] > arr[j]:
            inc[i] = max(inc[i], inc[j] + 1)
        if arr[N-i-1] > arr[N-j-1]:
            dec[N-i-1] = max(dec[N-i-1], dec[N-j-1] + 1)
            
ans = 0
for i in range(N):
    ans = max(ans, inc[i] + dec[i])
print(ans - 1)