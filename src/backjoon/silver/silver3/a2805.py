N, M = map(int, input().split())
trees = list(map(int, input().split()))
lo = 0
hi = max(trees)
mid = (lo + hi) // 2

def get_total_tree(height):
    log = 0
    for tree in trees:
        if tree > height:
            log += tree -  height
    return log

ans = 0
while lo <= hi:
    if get_total_tree(mid) >= M:
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1
    mid = (lo + hi) // 2
print(ans)