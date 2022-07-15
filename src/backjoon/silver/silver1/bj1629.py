A, B, C = map(int, input().split())

def square(a, b):
    if b == 1:
        return a % C

    if b % 2:
        return square(a, b // 2) ** 2 * a % C
    else:
        return square(a, b // 2) ** 2 % C
print(square(A, B))