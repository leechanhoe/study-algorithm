import sys
input = lambda : sys.stdin.readline().rstrip()

# N, M = map(int, input().split())
# stks = []
# for _ in range(M):
#     l = int(input())
#     stks.append(list(map(int, input().split())))

# now = 1
# for now in range(1, N + 1):
#     find = False
#     for i in range(M):
#         if stks[i] and stks[i][-1] == now:
#             now += 1
#             find = True
#             stks[i].pop()
#             break
        
#     if not find:
#         print("No")
#         exit()

# print("Yes")

n, m = map(int, input().split())
p = True
for _ in range(m):
    i = int(input())
    k = list(map(int, input().split()))
    for j in range(i-1):
        if k[j] < k[j+1]:
            p = False
            break
    if not p: break

print('Yes' if p else 'No') 