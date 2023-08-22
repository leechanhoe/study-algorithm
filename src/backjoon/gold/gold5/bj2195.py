S = input()
P = input()

ans = 0
i = 0
while i < len(P):
    ma = 0
    for j in range(len(S)):
        same = 0
        while j+same < len(S) and i+same < len(P) and S[j+same] == P[i+same]:
            same += 1
            ma = max(ma, same)
    
    i += ma
    ans += 1

print(ans)