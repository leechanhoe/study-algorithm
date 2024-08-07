def solution(board, skill):
    N = len(board)
    M = len(board[0])
    level = [[0] * (M + 1) for _ in range(N + 1)]
    for typ, r1, c1, r2, c2, degree in skill:
        val = -degree if typ == 1 else degree
        level[r1][c1] += val
        level[r1][c2+1] -= val
        level[r2+1][c1] -= val
        level[r2+1][c2+1] += val
    
    for i in range(N + 1):
        for j in range(N):
            level[i][j+1] += level[i][j]
    
    for i in range(N):
        for j in range(M + 1):
            level[i+1][j] += level[i][j]
            
    return sum([1 for j in range(M) for i in range(N)if board[i][j] + level[i][j] > 0])