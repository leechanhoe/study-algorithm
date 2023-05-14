N = int(input())
for i in range(1, N + 1):
    words = reversed(input().split())
    print(f"Case #{i}:", *words)