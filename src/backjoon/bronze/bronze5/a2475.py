a = map(int, input().split())
sum = sum([b * b for b in a])
print(sum % 10)