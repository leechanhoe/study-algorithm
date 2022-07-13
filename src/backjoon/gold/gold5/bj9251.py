a = input()
b = input()
cache = [0] * len(b)

for i in range(len(a)):
    ps = 0
    for j in range(len(b)):
        if ps < cache[j]:
            ps = cache[j]
        elif a[i] == b[j]:
            cache[j] = ps + 1
    print(cache)
print(max(cache))

# a = input()
# b = input()

# dp = [[0 for i in range(len(a) + 1)] for j in range(len(b) + 1)]

# for i in range(1, len(b) + 1):
#     for j in range(1, len(a) + 1):
#         if a[j - 1] == b[i - 1]:
#             dp[i][j] = dp[i - 1][j - 1] + 1
#         else:
#             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
# print(dp[-1][-1])