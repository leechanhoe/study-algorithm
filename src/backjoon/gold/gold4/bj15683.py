import copy

def rotate(dir):
    ret = [0] * 4
    for i in range(4):
        ret[i] = 1 if dir[i-1] else 0
    ret[1] *= -1
    ret[2] *= -1
    return ret

def watch(board, tv_num, dir):
    for i in range(4):
        if i % 2 == 0 and dir[i]: # 좌우 방향일경우
            for j in range(1, 8): 
                if 0 <= cctvs[tv_num][1] + j * dir[i] < M and board[cctvs[tv_num][0]][cctvs[tv_num][1] + j * dir[i]] != 6:
                    if board[cctvs[tv_num][0]][cctvs[tv_num][1] + j * dir[i]] == 0:
                        board[cctvs[tv_num][0]][cctvs[tv_num][1] + j * dir[i]] = -1
                    else:
                        continue
                else:
                    break
        elif i % 2 == 1 and dir[i]: # 상하 방향일경우
            for j in range(1, 8):
                if 0 <= cctvs[tv_num][0] + j * dir[i]< N and board[cctvs[tv_num][0] + j * dir[i]][cctvs[tv_num][1]] != 6:
                    if board[cctvs[tv_num][0] + j * dir[i]][cctvs[tv_num][1]] == 0:
                        board[cctvs[tv_num][0] + j * dir[i]][cctvs[tv_num][1]] = -1
                    else:
                        continue
                else:
                    break
def check_blind(board):
    blind = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 0:
                blind += 1
    global ans
    ans = min(ans, blind)

def dfs(board, tv_num):
    if tv_num == len(cctvs):
        check_blind(board)
        return
    dir = tv_type[cctvs[tv_num][2]]
    for i in range(4):
        if (cctvs[tv_num][2] == 5 and i == 1) or (cctvs[tv_num][2] == 2 and i == 2):
            break
        nb = copy.deepcopy(board)
        watch(nb, tv_num, dir)
        dfs(nb, tv_num + 1)
        dir = rotate(dir)
        
        

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
tv_type = [0, [1, 0, 0, 0], [1, 0, -1, 0], [1, -1, 0, 0], [1, -1, -1, 0], [1, -1, -1, 1]] # [우, 상, 좌, 하]
cctvs = []
for i in range(N):
    for j in range(M):
        if 0 < board[i][j] < 6:
            cctvs.append([i, j, board[i][j]])

ans = 64
dfs(board, 0)
print(ans)