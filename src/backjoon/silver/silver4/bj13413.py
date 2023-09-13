T = int(input())

for _ in range(T):
    N = int(input())
    a = list(input())
    b = list(input())

    diff = []
    for i in range(N):
        if a[i] != b[i]:
            diff.append(a[i])
    
    if not diff:
        print(0)
    else:
        print(diff.count('B') if diff.count('B') >= diff.count('W') else diff.count('W'))