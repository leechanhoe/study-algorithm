N = int(input())
arr = [int(input()) for _ in range(N)]
arr.sort()
ans = 5
for i in range(N):
    ans = min(ans, len(set(range(arr[i], arr[i] + 5)) - set(arr[i:min(i + 5, N)])))

print(ans)