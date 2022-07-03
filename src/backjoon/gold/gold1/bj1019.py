N = int(input())
cnt = [0] * 10

weight = 1 # 자리수
for step in range(len(str(N))): # 543이라고 치면
    replaced = int(str(N // 10) + "9") # 549가 되고
    remain = replaced - N
    for i in range(len(cnt)):
        cnt[i] += (N // 10 + 1) * weight # 54 - 0 + 1 = 55 일의 자리가 55번 반복
    for i in range(10 - remain, 10):
        cnt[i] -= weight # 일단 임의로 추가한 숫자인 544 ~ 549에서 일의 자리인 4~9를 빼줌
    for num in list(str(N)[:-1]):
        cnt[int(num)] -= remain * weight # 백의 자리와 십의 자리인 5,4도 6번 빼줌
    
    cnt[0] -= weight # 더한 일의 자리에서 0 하나는 제외해줌
    N //= 10 
    weight *= 10 # 다음에 543에서 일의 자리의 개수는 구했으니 다음 자리수인 54로 넘어가서 반복

print(*cnt)