"""
Global variables
"""
player_1 = "X"
player_2 = "O"
turn = 1

game_won = False

board = {
    "1": "-", "2": "-", "3": "-",
    "4": "-", "5": "-", "6": "-",
    "7": "-", "8": "-", "9": "-"
}

def print_board():
    count = 0
    for index, row in board.items():
        count += 1
        print(row, end=" ")
        if count == 3 or count == 6:
            print()
    print()

def set_board(user_input):
    position = int(user_input)
    if position > 9 or position < 1:
        print('Please enter a valid number between 1-9.')
        return False
    if board[user_input] != "-":
        print('This position is already taken.')
        return False
    print(f'{get_turn()} has been placed at position {user_input}.')
    board[user_input] = get_turn()
    return True

def player_turn():
    print_board()
    print(f"Player {get_turn()}'s turn")
    user_input =  input("Please enter a position 1-9: ")
    if isNumber(user_input) and set_board(user_input):
        check_win()
        next_turn()
    else:
        player_turn()

def get_turn():
    if turn % 2 == 0:
        return player_2
    return player_1

def next_turn():
    global turn
    turn = 1 if turn == 2 else 2 

def check_win():
    win_conditions = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
        [1, 4, 7],
        [2, 5, 8],
        [3, 6, 9],
        [1, 5, 9],
        [3, 5, 7]
    ]

    for condition in win_conditions:
        if board.get(str(condition[0])) ==  board.get(str(condition[1])) == board.get(str(condition[2])) != "-":
            global game_won
            game_won = True
            champion = get_turn()
            print_board()
            print(f"{champion} has won the game!")
            return

    for index, row in board.items():
        if row == "-":
            return
    game_won = True
    print("It's a draw!")

def isNumber(input):
    return True if input.isnumeric() else False

while True:
    player_turn()

    if (game_won):
        print("Thanks for playing!")
        break
