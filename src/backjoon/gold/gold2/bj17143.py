import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()


def fish(j):
    for i in range(R):
        if board[i][j]:
            x = board[i][j][2]
            board[i][j] = 0
            return x
    return 0


def move():
    global board  # board[i][j] 안에는 (s,d,z)의 값이 들어있음. 상어가 없는 경우엔 0이 들어있음
    new_board = [[0 for _ in range(C)] for _ in range(R)]  # 상어들의 새 위치를 담을 공간
    for i in range(R):
        for j in range(C):
            if board[i][j]:
                # 이 상어의 다음 위치는
                ni, nj, nd = get_next_loc(i, j, board[i][j][0], board[i][j][1])
                if new_board[ni][nj]:
                    new_board[ni][nj] = max(
                        new_board[ni][nj],
                        (board[i][j][0], nd, board[i][j][2]),
                        key=lambda x: x[2],
                    )
                else:
                    new_board[ni][nj] = (board[i][j][0], nd, board[i][j][2])

    board = new_board  # board가 이제 상어들의 새 위치를 가리키도록


def get_next_loc(i, j, speed, dir):

    if dir == UP or dir == DOWN:  # i
        cycle = R * 2 - 2
        if dir == UP:
            speed += 2 * (R - 1) - i
        else:
            speed += i

        speed %= cycle
        if speed >= R:
            return (2 * R - 2 - speed, j, UP)
        return (speed, j, DOWN)

    else:  # j
        cycle = C * 2 - 2
        if dir == LEFT:
            speed += 2 * (C - 1) - j
        else:
            speed += j

        speed %= cycle
        if speed >= C:
            return (i, 2 * C - 2 - speed, LEFT)
        return (i, speed, RIGHT)


UP, DOWN, RIGHT, LEFT = 1, 2, 3, 4
R, C, M = map(int, input().split())
board = [[0 for _ in range(C)] for _ in range(R)]

for i in range(M):
    r, c, s, d, z = map(int, input().split())
    r, c = r - 1, c - 1
    board[r][c] = (s, d, z)

ans = 0
for j in range(C):
    ans += fish(j)
    move()

print(ans)

# import sys
# input = lambda : sys.stdin.readline().rstrip()

# R, C, M = map(int, input().split())
# board = [[0] * (C + 1) for _ in range(R + 1)]
# ans = 0
# dir = [0, (-1, 0), (1, 0), (0, 1), (0, -1)]

# sharks = [0]
# for i in range(1, M + 1):
#     r, c, s, d, z = map(int, input().split())
#     sharks.append([i, r, c, s, d, z, True]) # i = 상어 번호, True = 생존
#     board[r][c] = i

# def catch(c):
#     for i in range(1, R + 1):
#         if board[i][c]:
#             global ans
#             ans += sharks[board[i][c]][5]
#             sharks[board[i][c]][6] = False
#             return

# def move():
#     for shark in sharks:
#         if not shark or not shark[6]:
#             continue

#         if shark[4] < 3:
#             y = (dir[shark[4]][0] * shark[3] % (2 * R - 2) + shark[1]) % (2 * R - 2)
#             if shark[4] == 1 and shark[3] >= shark[1]:
#                 shark[4] = 2 if shark[3] + R - shark[1] - 1 // (2 * R - 2) % 2 else 1
#             elif shark[4] == 2 and shark[3] > R - shark[1]:
#                 shark[4] = 1 if R - shark[1] + 1 + shark[3] // (2 * R - 2) % 2 else 2
#             shark[1] = (y if y <= R else R - (y - R)) if y != 0 else 2
#         else :
#             x = (dir[shark[4]][1] * shark[3] % (2 * C - 2) + shark[2]) % (2 * C - 2)
#             if shark[4] == 4 and shark[3] >= shark[2]:
#                 shark[4] = 3 if shark[3] + C - shark[2] - 1 // (2 * C - 2) % 2 else 4
#             elif shark[4] == 3 and shark[3] > C - shark[2]:
#                 shark[4] = 4 if C - shark[2] + 1 + shark[3] // (2 * C - 2) % 2 else 3
#             shark[2] = (x if x <= C else C - (x - C)) if x != 0 else 2

#         if board[shark[1]][shark[2]]: # 이미 다른 상어가 있으면
#             if sharks[board[shark[1]][shark[2]]][5] > shark[5]:
#                 shark[6] = False
#             else:
#                 sharks[board[shark[1]][shark[2]]][6] = False
#                 board[shark[1]][shark[2]] = shark[0]
#         else:
#             board[shark[1]][shark[2]] = shark[0]

# for x in range(1, C + 1):
#     print(x)
#     for i in range(1, R + 1):
#         print(board[i][1:])
#     catch(x)
#     board = [[0] * (C + 1) for _ in range(R + 1)]
#     move()
#     print()
#     for i in range(1, R + 1):
#         print(board[i][1:])

# # for x in range(1, C + 1):
# #     catch(x)
# #     board = [[0] * (C + 1) for _ in range(R + 1)]
# #     move()

# print(ans)