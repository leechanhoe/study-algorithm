import sys
input = lambda : sys.stdin.readline().rstrip()

def rotate(board):
    ret = [[0] * N for i in range(N)]
    for i in range(N):
        for j in range(N):
            ret[i][j] = board[j][N-i-1]
    return ret

def check(board):
    global ans
    for i in range(N):
        flat = 1
        change = False
        for j in range(1, N + 1):
            if j == N: # 끝까지 다 왔으면
                if change:
                    break
                ans += 1
                break
            if abs(board[i][j] - board[i][j-1]) > 1: # 높이차이가 2 이상일경우
                break

            if board[i][j] == board[i][j-1]:
                flat += 1
                if change and flat == L: # 낮아진상태인데 계단 길이를 충족했을경우
                    change = False
                    flat = 0
            elif board[i][j] < board[i][j-1]: # 낮아질경우
                if not change:
                    if L == 1: # L이 1이면 그 자리에서 내려갈 수 있다 대신 평평함은 x
                        flat = 0
                    else: 
                        flat = 1
                        change = True
                else:
                    break
            elif board[i][j] > board[i][j-1]: # 높아질경우
                if not change and flat >= L: # 낮아져서 계단 길이를 채우는중인 상태가 아니고
                    flat = 1                 # 평평함이 계단 길이 이상일경우
                else:
                    break
            else:
                break

N, L = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
ans = 0
check(board)
check(rotate(board)) # 90도 돌려서 한번더
print(ans)