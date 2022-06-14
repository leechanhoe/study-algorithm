N, K = map(int, input().split())
arr = list(map(int, input().split()))
multi = []
ans = 0
for i, item in enumerate(arr):
    if item in multi: # 꽂혀있는게 사용되면
        continue

    if len(multi) >= N: # 꽂을곳이 부족하면
        last_use = (-1, 0) 
        for pluged_in in multi: # 멀티탭을 탐색해서
            for j in range(i, K):
                if pluged_in == arr[j]: # 사용계획을 탐색해서 멀티탭에 꽂혀있는 것 중 가장 늦게 사용되는 것 찾기
                    last_use = (pluged_in, j) if j > last_use[1] else last_use 
                    break
                if j == K - 1:
                    last_use = (pluged_in, j)
        
        multi.remove(last_use[0])
        ans += 1
    multi.append(item)
print(ans)