a, b = sorted(map(int, input().split()))
print(b*(b+1)//2 - a*(a-1)//2)