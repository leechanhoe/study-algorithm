def check_max(arr, n):
    max_cnt = 0
    for i in range(n):
        row_cnt = 1
        for j in range(n - 1):
            if arr[i][j] == arr[i][j+1]:
                row_cnt += 1
                max_cnt = max(max_cnt, row_cnt)
            else :
                row_cnt = 1

    for i in range(n):
        col_cnt = 1
        for j in range(n - 1):
            if arr[j][i] == arr[j+1][i]:
                col_cnt += 1
                max_cnt = max(max_cnt, col_cnt)
            else :
                col_cnt = 1
                
    return max_cnt

n = int(input())
board = [list(input()) for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(n):
        if(j < n - 1):
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
            ans = max(check_max(board, n), ans)
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
        if(i < n - 1):
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
            ans = max(check_max(board, n), ans)
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]

print(ans)