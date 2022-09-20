def go(turn):
    # 만약 현재 맵 상태에서 상대턴이 이겼다면 더 수를 둘 필요가 없다.
    if test(3 - turn): # 3 - turn은 상대방을 의미한다 
        return -1

    min_ = 2 # -1 : 짐 / 0 : 비김 / 1 : 이김 / 일단 최댓값 넣기
    for y in range(3):
        for x in range(3):
            if board[y][x] == 0:
                board[y][x] = turn # 상대방이 지면(상대방은 -1반환) 내가 이기는 길이 있다(나는 1반환).
                #상대가 -1을 반환하기 기대함 - 그러므로 최솟값 구함
                min_ = min(min_, go(3 - turn))
                board[y][x] = 0

    # 값 변화가 없었으면 Draw
    if min_ == 2 or min_ == 0:
        return 0
    return -min_ # 상대방이 이기는 길밖에 없으면 (상대방은 1반환) 내가 이기는 길이 없다(나는 -1반환).

def test(turn):
    for y in range(3):
        if board[y][0] == turn and board[y][0] == board[y][1] and board[y][1] == board[y][2]: 
            return True

    for x in range(3):
        if board[0][x] == turn and board[0][x] == board[1][x] and board[1][x] == board[2][x]:
            return True

    if board[0][0] == turn and board[0][0] == board[1][1] and board[1][1] == board[2][2]:
        return True

    if board[0][2] == turn and board[0][2] == board[1][1] and board[1][1] == board[2][0]:
        return True

    return False

board = []
order = 0
for i in range(3):
    board.append(list(map(int, input().split())))
    for j in range(3):
        if board[i][j] != 0:
            order += 1

result = 0
if order % 2 == 0:
    result = go(1)
else:
    result = go(2)

if result == 0:
    print("D")
elif result == 1:
    print("W")
else:
    print("L")