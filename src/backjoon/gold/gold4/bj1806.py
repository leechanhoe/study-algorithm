N, S = map(int, input().split())
arr = list(map(int, input().split()))

psum = [0] * (N + 1)
for i in range(1, N + 1):
    psum[i] = psum[i-1] + arr[i-1]

start = 0
end = 1
ans = 987654321
while start < N:
    if psum[end] - psum[start] >= S:
        ans = min(ans, end - start)
        start += 1
    else:
        if end == N:
            start += 1
        else:
            end += 1
if ans == 987654321:
    ans = 0
print(ans)