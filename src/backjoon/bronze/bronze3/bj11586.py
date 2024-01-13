# N = int(input())
# mirror = [input() for _ in range(N)]
# K = int(input())

# if K == 1:
#     for i in range(N):
#         print(mirror[i])
# elif K == 2:
#     for i in range(N):
#         print(mirror[i][::-1])
# elif K == 3:
#     for i in range(N):
#         print(mirror[-i])   
n = int(input())
mirror = [input().rstrip() for _ in range(n)]
k = int(input())

if k == 1:  # 원본 출력
    print(*mirror, sep='\n')
elif k == 2:  # 좌우 반전
    print(*[i[::-1] for i in mirror], sep='\n')
else:  # 상하 반전
    print(*mirror[::-1], sep='\n')