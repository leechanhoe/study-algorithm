N, M = map(int, input().split())
arr = list(map(int, input().split()))

def check(mid):
    mi = arr[0]
    ma = arr[0]
    div = 1
    for i in range(N):
        mi = min(mi, arr[i])
        ma = max(ma, arr[i])
        if mid < ma - mi:
            div += 1
            if M < div:
                return False
            mi = arr[i]
            ma = arr[i]
    return True

ans = 0
le = 0
ri = 10000
while le <= ri:
    mid = (le + ri) // 2
    if check(mid):
        ri = mid - 1
        ans = mid
    else:
        le = mid + 1
        
print(ans)