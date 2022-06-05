N, M = map(int, input().split())
lessons = list(map(int, input().split()))

def f(n):
    sum = 0
    cnt = 1
    for lesson in lessons:
        if sum + lesson <= n:
            sum += lesson
        else:
            cnt += 1
            sum = lesson        
    return cnt

lo = max(lessons)
hi = sum(lessons)
mid = (lo + hi) // 2
ans = 0
while lo <= hi: # 최솟값을 구하니 <= 
    if f(mid) <= M: # cnt가 작다는건 블루레이 크기가 크다는것 
        ans = mid
        hi = mid - 1
    else:
        lo = mid + 1
    mid = (lo + hi) // 2
print(ans)