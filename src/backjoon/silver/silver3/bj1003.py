import sys
input = sys.stdin.readline

def fibonacci(n):
    if n == 0:
        return 1, 0
    if n == 1:
        return 0, 1
    
    prev = fibonacci(n - 1)
    cnt0 = prev[1]
    cnt1 = sum(prev)
    return cnt0, cnt1
    
for i in range(int(input())):
    cnt = fibonacci(int(input()))
    print(f'{cnt[0]} {cnt[1]}')