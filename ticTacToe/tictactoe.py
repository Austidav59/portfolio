# 1. Name:
#      -Austin Davise-
# 2. Assignment Name:
#      Lab 01: Tic-Tac-Toe
# 3. Assignment Description:
#      Play the game of Tic-Tac-Toe
# 4. What was the hardest part? Be as specific as possible.
#      -The hardest part about this program was gettin it to display correctly on the screen. -
# 5. How long did it take for you to complete the assignment?
#     6 hours

import json

# The characters used in the Tic-Tac-Too board.
# These are constants and therefore should never have to change.
X = 'X'
O = 'O'
BLANK = ' '
# A blank Tic-Tac-Toe board. We should not need to change this board;
# it is only used to reset the board to blank. This should be the format
# of the code in the JSON file.


blank_board = {  
            "board": [
                " ", " ", " ",
                " ", " ", " ",
                " ", " ", " " ]
        }





def read_board(board):
    '''Read the previously existing board from the file if it exists.'''
    # Put file reading code here.
    return blank_board


def save_board(board):
    '''Save the current game to a file.'''
    # Put file writing code here.
    board = read_board(board)
    with open("board.json", 'w') as file:
        json.dump(board, file, indent=4)



def display_board(board):
    '''Display a Tic-Tac-Toe board on the screen in a user-friendly way.'''
    # Put display code here.
    a = ""
    b = ""
    c = ""
    d = ""
    e = ""
    f = ""
    g = ""
    h = ""
    j = ""
    index = 0

    for i in board["board"]:
        if index == 0:          
            index = index + 1
            a = i
        elif index == 1:
            index = index + 1
            b = i
        elif index == 2:
            index = index + 1
            c = i
        elif index == 3:
            index = index + 1
            d = i
        elif index == 4:
            index = index + 1
            e = i
        elif index == 5:
            index = index + 1
            f = i
        elif index == 6:
            index = index + 1
            g = i
        elif index == 7:
            index = index + 1
            h = i
        else:
            index = index + 1
            j = i

    

    print(f" {a} | {b} | {c} ")
    print(f"---+---+---")
    print(f" {d} | {e} | {f} ")
    print(f"---+---+---")
    print(f" {g} | {h} | {j} \n")
    
def is_x_turn(board):
    '''Determine whose turn it is.'''
    turn = 0
    x_turn = [0,2,4,6,8]
    answer = False

    # Put code here determining if it is X's turn.
    for i in board["board"]:
        if (i == "X") or (i == "O"):
            turn = turn + 1
    
    for i in x_turn:
        if i == turn:
            answer = True
            return answer
        else:
            answer = False
    return answer





def play_game(board):
    '''Play the game of Tic-Tac-Toe.'''
    if is_x_turn(board) == True:
        player_x = input("x> ")
        if player_x != "q":
            index = int(player_x) - 1
            board["board"][index] = X
            with open("board.json", "w") as write_board:
                json.dump(board, write_board)

            display_board(board)
    
            if game_done(board, message=False) == True:
                loop = 0
                return loop

        else:
            loop = 0
            return loop
    
    else:
        #play o's turn

        player_o = input("o> ")
        if player_o != "q":
            index = int(player_o) - 1
            board["board"][index] = O
            with open("board.json", "w") as write_board:
                json.dump(board, write_board)

            display_board(board)
            if game_done(board, message=False) == True:
                loop = 0
                return loop

        else:
            loop = 0
            return loop
    # Put game play code here. Return False when the user has indicated they are done.

def game_done(board, message=False):
    '''Determine if the game is finished.'''
    # Game is finished if someone has completed a row.
    for row in range(3):
        if board["board"][row * 3] != BLANK and board["board"][row * 3] == board["board"][row * 3 + 1] == board["board"][row * 3 + 2]:
            if message:
                print("The game was won by", board["board"][row * 3])
            return True

    # Game is finished if someone has completed a column.
    for col in range(3):
        if board["board"][col] != BLANK and board["board"][col] == board["board"][3 + col] == board["board"][6 + col]:
            if message:
                print("The game was won by", board["board"][col])
            return True

    # Game is finished if someone has a diagonal.
    if board["board"][4] != BLANK and (board["board"][0] == board["board"][4] == board["board"][8] or
                                       board["board"][2] == board["board"][4] == board["board"][6]):
        if message:
            print("The game was won by", board["board"][4])
        return True

    # Game is finished if all the squares are filled.
    tie = True
    for square in board["board"]:
        if square == BLANK:
            tie = False
            break
    if tie:
        if message:
            print("The game is a tie!")
        return True

    return False

# These user-instructions are provided and do not need to be changed.
print()
print("Enter 'q' to suspend your game. Otherwise, enter a number from 1 to 9")
print("where the following numbers correspond to the locations on the grid:")
print(" 1 | 2 | 3 ")
print("---+---+---")
print(" 4 | 5 | 6 ")
print("---+---+---")
print(" 7 | 8 | 9 \n")
print("The current board is:")

# The file read code, game loop code, and file close code goes here.
def main():
    with open("board.json", "r") as board:
            # Put code here determining if it is X's turn.
        loaded_board = json.load(board)
        user_input = ""
        loop = -1
        ask = 0
        while loop != 0:
            if ask < 1:
                ask = ask + 1
                print()
                game = input("new or resume: ")
                if game == "new":
                    save_board(loaded_board)
                    if play_game(loaded_board) == 0:
                        loop = 0
                else:
                    if play_game(loaded_board) == 0:
                        loop = 0
            else:
                if play_game(loaded_board) == 0:
                        loop = 0

main()
                


