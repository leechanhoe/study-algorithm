import sys
input = lambda : sys.stdin.readline().rstrip()

def down(): # i일때 i로 나오는지
    for x in range(N):
        nx = x
        for i in range(H):
            if ladder[i][nx] > 0:
                nx += 1
            elif ladder[i][nx] < 0:
                nx -= 1

        if x != nx:
            return False
    return True

def add(y, n):
    global ans
    for i in range(y, H):
        for j in range(N-1):
            if n >= ans:
                return

            if ladder[i][j] == 0 and ladder[i][j+1] == 0:
                ladder[i][j] = 1
                ladder[i][j+1] = -1
                nn = n + 1

                if down(): # 조건만족하면
                    ans = nn
                    ladder[i][j] = 0
                    ladder[i][j+1] = 0
                    return

                if nn < 3:
                    add(i, nn)
                ladder[i][j] = 0
                ladder[i][j+1] = 0

N, M, H = map(int, input().split())
ladder = [[0] * N for _ in range(H)]
for i in range(M):
    a, b = map(int, input().split())
    ladder[a-1][b-1] = 1 # 오른쪽
    ladder[a-1][b] = -1 # 왼쪽
ans = 4

if down():
    print(0)
    exit(0)

add(0, 0)
if ans > 3:
    ans = -1
print(ans)