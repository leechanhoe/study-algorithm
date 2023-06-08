L, P = map(int, input().split())
nums = list(map(int, input().split()))
for i in range(5):
    print(nums[i] - L * P, end=' ')