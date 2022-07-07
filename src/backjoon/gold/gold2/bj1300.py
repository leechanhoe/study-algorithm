N = int(input())
K = int(input())
le = 1
ri = N ** 2
ans = 0

while le <= ri:
    cnt = 0
    mid = (le + ri) // 2
    for i in range(1, N + 1):   # K번째 인덱스는 K번쨰로 큰 수이므로 K보다 작은 수들을 더하면 된다.
        cnt += min(mid // i, N) # 예를들어 N이 10이고 K가 20일때 20을 1~20까지 나눈것의 몫을 더한다. 
    if cnt < K:                 # N * N 까지 있으므로 몫은 N을 넘으면 안된다.
        le = mid + 1
    else:
        ri = mid - 1
        ans = mid
print(ans)