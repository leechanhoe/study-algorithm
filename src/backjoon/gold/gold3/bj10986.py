from collections import Counter
N, M = map(int, input().split())
arr = list(map(int, input().split()))
ps = [arr[0]]
for i in range(1, N):
    ps.append(ps[i-1] + arr[i])

ans = 0 # 부분합의 나머지들을 따로 구해서 같은 나머지중에 2개를 고르면 된다
remain = Counter(list(map(lambda x : x % M, ps)))
for key in remain.keys():
    ans += remain[key] * (remain[key] - 1) // 2
    if key == 0:
        ans += remain[key]
print(ans)