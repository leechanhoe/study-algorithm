N = int(input())
broken = []
if int(input()):
    broken = input().split()

ans = abs(N - 100)
for i in range(1000001):
    broke = False
    for ch in str(i):
        if ch in broken:
            broke = True
            break
    if broke:
        continue
    ans = min(ans, abs(i - N) + len(str(i)))
print(ans)