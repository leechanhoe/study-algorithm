N = input()
for i in range(1, len(N)):
    le = 1
    ri = 1
    for j in range(i):
        le *= int(N[j])
    for j in range(i, len(N)):
        ri *= int(N[j])
    if le == ri:
        print("YES")
        exit(0)
    
print("NO")