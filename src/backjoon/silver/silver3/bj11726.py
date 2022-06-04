# n = int(input()) Solving with memoization
# cache = [0] * (n + 1)

# def f(n):
#     if cache[n]:
#         return cache[n]
    
#     cache[n] = n if n <= 3 else f(n - 1) + f(n - 2)
#     return cache[n]
# print(f(n) % 10007)

s = [0, 1, 2] # Solving with Tabulation
for i in range(3, 1001):
  s.append(s[i - 2] + s[i - 1])
n = int(input())
print(s[n] % 10007)