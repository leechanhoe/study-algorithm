N, S = map(int, input().split())
arr = list(map(int, input().split()))

psum = [0] * (N + 1)
for i in range(1, N + 1):
    psum[i] = psum[i-1] + arr[i-1]

start = 0 # 포인터 2개를 준비한다. 시작과 끝을 알 수 있도록 start, end 라고 한다.
end = 0 # 맨 처음에는 start = end = 0이며, 항상 start <= end를 만족해야 한다.
ans = 987654321
while start < N: # 만약 현재 부분합이 S 이상이거나, 이미 end = N이면
    if psum[end] - psum[start] >= S: 
        ans = min(ans, end - start)
        start += 1 # start를 1 늘리고
    else:
        if end == N:
            start += 1
        else:
            end += 1 # 그렇지 않다면 end를 늘린다
if ans == 987654321:
    ans = 0
print(ans)