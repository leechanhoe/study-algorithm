game_board = "*_________" # 칸 번호와 인덱스가 일치하게끔 설계

AI = True
AI_MARK = "O"

HUMAN = False
HUMAN_MARK = "X"



def main():
    print("1. AI")
    print("2. HUMAN")
    user_input = input("Select First Player : ")
        
    if user_input == "1":
        player = AI
        
    elif user_input == "2":
        player = HUMAN
            
    else:
        print("Incorrect Input.")
        user_input = input("Select First Player : ")
        
    if player == HUMAN:
        show()
            
    while findEmpty(game_board) and not isEnd(game_board):
        if player == AI:
            index, _ = minimax(game_board, 9, AI)
            place(index, AI_MARK)
            player = HUMAN
            
        else:
            index = indexInput()
            place(index, HUMAN_MARK)
            player = AI
            
        show()   
    ending()

def findEmpty(board): # 빈 칸의 인덱스가 담긴 튜플을 리턴
    return tuple(x for x, cell in enumerate(board) if cell == "_")

def isWin(board, player_mark):
    for (a, b, c) in ((1, 2, 3), (4, 5, 6), (7, 8, 9),
                      (1, 4, 7), (2, 5, 8), (3, 6, 9),
                      (1, 5, 9), (3, 5, 7)):
        if board[a] == board[b] == board[c]:
            if board[a] == player_mark:
                return True
    
    return False

def isEnd(board):
    return isWin(board, AI_MARK) or isWin(board, HUMAN_MARK)

def evaluate(board): # 누군가 이겼으면 -1, 1 (True) 를 리턴, 그렇지 않으면 0 (False) 를 리턴
    if isWin(board, AI_MARK): return 1
    elif isWin(board, HUMAN_MARK): return -1
    else: return 0

def minimax(board, depth, player): # player 가 AI 면 최선의 수를, HUMAN 이면 최악의 수를 (HUMAN 입장에선 최선의 수) 둔다고 가정
    index = -1
    if (depth == 0) or (isEnd(board)) or not findEmpty(board):
        return -1, evaluate(board)
        
    if player == AI:
        value = float('-inf')
        for each in findEmpty(board):
            _, score = minimax(board[:each] + AI_MARK + board[each+1:], depth-1, HUMAN)
            if score > value:
                value = score
                index = each
            if score == 1: # alpha 가지치기 / TicTacToe 에서 1 (승리) 보다 최선은 없으므로 1을 찾으면 바로 탐색 종료.
                break
        
    else:
        value = float('inf')
        for each in findEmpty(board):
            _, score = minimax(board[:each] + HUMAN_MARK + board[each+1:], depth-1, AI)
            if score < value:
                value = score
                index = each
            if score == -1: # beta 가지치기 / TicTacToe 에서 -1 (패배) 보다 최악은 없으므로 -1을 찾으면 바로 탐색 종료.
                break
                
    return index, value

def isValid(index): # 착수 가능 위치인지 확인
    return index in findEmpty(game_board)
    
def place(index, player_mark): # 착수
    if isValid(index):
        global game_board
        game_board = game_board[:index] + player_mark + game_board[index+1:]

def indexInput():
    num = -1
    while num not in findEmpty(game_board):
        input_string = ''
        while not input_string.isdecimal():
            input_string = input("\nYour Turn : ")
        num = int(input_string)
        
    return num

def show():
    print("--------------------")
    print(game_board[1], game_board[2], game_board[3])
    print(game_board[4], game_board[5], game_board[6])
    print(game_board[7], game_board[8], game_board[9])
    
def ending():
    if evaluate(game_board) == 1: print("AI WIN")
    elif evaluate(game_board) == -1: print("HUMAN WIN")
    else: print("TIE")

if __name__ == '__main__':
    main()