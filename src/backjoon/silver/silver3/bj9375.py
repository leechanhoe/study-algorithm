T = int(input())

for i in range(T):
    N = int(input())
    dic = {}
    for j in range(N):
        s1, s2 = input().split()
        if s2 in dic:
            dic[s2] += 1
        else:
            dic[s2] = 1

    ans = 1
    for key in dic.keys():
        ans *= dic[key] + 1
    print(ans-1)
