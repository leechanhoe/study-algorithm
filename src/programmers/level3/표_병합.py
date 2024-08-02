def solution(commands):
    ans = []
    merge = [[(i, j) for j in range(50)] for i in range(50)]
    cell = [["EMPTY"] * 50 for _ in range(50)]
    
    for cmd in commands:
        cmd = cmd.split()
        if cmd[0] == 'UPDATE':
            
            if len(cmd) == 4:
                r, c, value = int(cmd[1]) - 1, int(cmd[2]) - 1, cmd[3]
                x, y = merge[r][c]
                cell[x][y] = value
                
            elif len(cmd) == 3:
                value1, value2 = cmd[1], cmd[2]
                for i in range(50):
                    for j in range(50):
                        if cell[i][j] == value1:
                            cell[i][j] = value2
        
        elif cmd[0] == 'MERGE':
            r1, c1, r2, c2 = int(cmd[1]) - 1, int(cmd[2]) - 1, int(cmd[3]) - 1, int(cmd[4]) - 1
            x1, y1 = merge[r1][c1]
            x2, y2 = merge[r2][c2]
            if cell[x1][y1] == "EMPTY":
                cell[x1][y1] = cell[x2][y2]
            
            for i in range(50):
                for j in range(50):
                    if merge[i][j] == (x2,y2):
                        merge[i][j] = (x1,y1)
                        
        elif cmd[0] == 'UNMERGE':
            r, c = int(cmd[1]) - 1, int(cmd[2]) - 1
            x, y = merge[r][c]
            value_tmp = cell[x][y]
            for i in range(50):
                for j in range(50):
                    if merge[i][j] == (x,y):
                        merge[i][j] = (i,j)
                        cell[i][j] = "EMPTY"
                        
            cell[r][c] = value_tmp
            
        elif cmd[0] == 'PRINT':
            r, c = int(cmd[1]) - 1, int(cmd[2]) - 1
            x, y = merge[r][c]
            ans.append(cell[x][y])
        
    return ans