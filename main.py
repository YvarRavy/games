"""
This is the main file for the tic tac toe game.
"""

"""
Global variables
"""
player_1 = "X"
player_2 = "O"

turn = 1

game_won = False
champion = ""

board = [
    ["-", "-", "-"],
    ["-", "-", "-"],
    ["-", "-", "-"]
]

""" 
    All board related functions
"""
def print_board(board):
    """
    Prints the board.
    """
    for row in board:
        for slot in row:
            print(slot, end=" ")
        print()

def set_board(user_input):
    """
    Sets the board.
    """
    position = int(user_input)
    if position == 1:
        if (board[0][0] == "-"):
            board[0][0] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 2:
        if (board[0][1] == "-"):
            board[0][1] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 3:
        if (board[0][2] == "-"):
            board[0][2] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 4:
        if (board[1][0] == "-"):
            board[1][0] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 5:
        if (board[1][1] == "-"):
            board[1][1] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 6:
        if (board[1][2] == "-"):
            board[1][2] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 7:
        if (board[2][0] == "-"):
            board[2][0] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 8:
        if (board[2][1] == "-"):
            board[2][1] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    elif position == 9:
        if (board[2][2] == "-"):
            board[2][2] = get_turn() 
        else:
            print(f"Slot {user_input} is already taken.")
            return
    else:
        print(f"Slot {user_input} is not a valid.")
        return

    print(f"{get_turn()} has been placed at {user_input}")

"""
All player related functions
"""
def player_turn(turn):
    """
    validates the player's turn.
    """
    user_input =  input("Please enter a position 1-9: ")
    if (isNumber(user_input)):
        set_board(user_input)
    else:
        player_turn(turn)

    check_win()
    next_turn()

def get_turn():
    """
    Gets the turn.
    """
    if turn % 2 == 0:
        return player_2
    else:
        return player_1


def next_turn():
    """
    Sets the next turn.
    """
    global turn
    turn = 1 if turn == 2 else 2 

"""
    Global game functions
"""
def check_win():
    """
    Checks if the game has been won.
    """
    global game_won
    global champion

    if board[0][0] == board[0][1] == board[0][2] != "-":
        game_won = True
        champion = f"Player: {get_turn()} wins!"
    elif board[1][0] == board[1][1] == board[1][2] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    elif board[2][0] == board[2][1] == board[2][2] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    elif board[0][0] == board[1][0] == board[2][0] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    elif board[0][1] == board[1][1] == board[2][1] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    elif board[0][2] == board[1][2] == board[2][2] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    elif board[0][0] == board[1][1] == board[2][2] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    elif board[0][2] == board[1][1] == board[2][0] != "-":
        champion = f"Player: {get_turn()} wins!"
        game_won = True
    else:
        for row in board:
            for slot in row:
                if slot == "-":
                    return
        game_won = True
        champion = "It's a draw!"

"""
All validator functions
"""
def isNumber(input):
    """
    Validates input
    """
    if not input.isnumeric() or int(input) > 9 or int(input) < 1:
        print('Please enter a valid number between 1-9.')
        return False
    else:
        return True

"""
Game loop
"""
while True:
    print_board(board)
    if (turn % 2 == 0):
        print("Player 2's turn")
        player_turn(turn)
    else:
        print("Player 1's turn")
        player_turn(turn)

    if (game_won):
        print_board(board)
        print("Game over")
        print(champion)
        print("Thanks for playing!")
        break