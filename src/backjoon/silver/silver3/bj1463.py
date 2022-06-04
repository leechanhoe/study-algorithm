# n = int(input()) 타뷸레이션 방식으로 풀기
# dp = [-1] * (n + 1)
# dp[1] = 0

# for i in range(2, n + 1):
#     if i % 6 == 0:
#         dp[i] = min(dp[i // 3], dp[i // 2]) + 1
#     elif i % 3 == 0:
#         dp[i] = min(dp[i - 1], dp[i // 3]) + 1
#     elif i % 2 == 0:
#         dp[i] = min(dp[i - 1], dp[i // 2]) + 1
#     else:
#         dp[i] = dp[i - 1] + 1

# print(dp[n])

# n = int(input()) 메모이제이션 방식으로 풀기
# cache = [-1] * (n + 1)
# cache[1] = 0

# def making1(n):
#     if(cache[n] != -1):
#         return cache[n]

#     if n % 6 == 0:
#         cache[n] = min(making1(n // 3), making1(n // 2)) + 1
#     elif n % 3 == 0:
#         cache[n] = min(making1(n - 1), making1(n // 3)) + 1
#     elif n % 2 == 0:
#         cache[n] = min(making1(n - 1), making1(n // 2)) + 1
#     else:
#         cache[n] = making1(n - 1) + 1
#     return cache[n]

# print(making1(n))

from collections import deque #Solving with BPS

n = int(input())
dq = deque()
dq.append((n, 0))
chk = [False] * (n + 1)
chk[n] = True

while dq:
    x, d = dq.popleft()
    if x == 1:
        print(d)
        break

    if x % 3 == 0 and not chk[x // 3]:
        chk[x // 3] = True
        dq.append((x // 3, d + 1))

    if x % 2 == 0 and not chk[x // 2]:
        chk[x // 2] = True
        dq.append((x // 2, d + 1))

    if not chk[x - 1]:
        chk[x - 1] = True
        dq.append((x - 1, d + 1))