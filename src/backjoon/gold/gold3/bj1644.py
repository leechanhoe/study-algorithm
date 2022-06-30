N = int(input())
a = [False, False] + [True] * (N-1)
primes = [0]
for i in range(2, N + 1):
    if a[i]:
        primes.append(i)
        for j in range(i * 2, N + 1, i):
            a[j] = False

psum = [0] * len(primes)
for i in range(1, len(primes)):
    psum[i] = psum[i-1] + primes[i]

start = end = ans = 0
while start < len(psum):
    if psum[end] - psum[start] < N:
        end += 1
        if end == len(psum):
            break
    elif psum[end] - psum[start] > N:
        start += 1
    else:
        ans += 1
        start += 1
print(ans)