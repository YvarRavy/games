#include <iostream>
void player_turn();

std::string board[3][3] = {
    {"-", "-", "-"},
    {"-", "-", "-"},
    {"-", "-", "-"}
};

char player_1 = 'X';
char player_2 = 'O';
int turn = 1;

std::string champion;
bool game_won = false;

void print_board() {
    // loop through board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int is_number(std::string input) {
    char c = input[0];
    std::cout << c << std::endl;
    if (std::isdigit(c) == 0) return false;
    if (c < '1' || c > '9') return false;
    return true;
}

char get_turn() {
    if (turn % 2 == 0) {
        return player_2;
    } else {
        return player_1;
    }
}

void next_turn() {
    if (turn == 1) {
        turn = 2;
    } else {
        turn = 1;
    }
}

void check_win() {
    if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && board[0][2] != "-" ||
        (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && board[1][2] != "-" ||
        (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && board[2][2] != "-" ||
        (board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && board[2][0] != "-" ||
        (board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && board[2][1] != "-" ||
        (board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && board[2][2] != "-" ||
        (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[2][2] != "-" ||
        (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[2][0] != "-"
    ) {
        champion = "Player " + std::to_string(get_turn()) + " wins!";
        game_won = true;
    }
}

void set_board(std::string input) {
    std::cout << input;
    if (input == "1") {
        if (board[0][0] == "-") {
            board[0][0] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "2") {
        if (board[0][1] == "-") {
            board[0][1] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "3") {
        if (board[0][2] == "-") {
            board[0][2] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "4") {
        if (board[1][0] == "-") {
            board[1][0] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "5") {
        if (board[1][1] == "-") {
            board[1][1] = get_turn();
        } else {
            player_turn();
            std::cout << "Invalid move" << std::endl;
        }
    } else if (input == "6") {
        if (board[1][2] == "-") {
            board[1][2] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "7") {
        if (board[2][0] == "-") {
            board[2][0] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "8") {
        if (board[2][1] == "-") {
            board[2][1] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else if (input == "9") {
        if (board[2][2] == "-") {
            board[2][2] = get_turn();
        } else {
            std::cout << "Invalid move" << std::endl;
            player_turn();
        }
    } else {
            std::cout << "fucking retard act normal" << std::endl;
    }

    check_win();
    next_turn();
}

void player_turn() {
    print_board();
    std::string input = "";
    std::cout << "Please enter a number between 1 and 9: " << std::endl;
    std::cin >> input;
    if (is_number(input)) {
        set_board(input);
    } else {
        std::cout << "Invalid input" << std::endl;
        player_turn();
    }
}

int main() {
    while (true) {
        std::cout << "Player " << turn << " turn: " << std::endl;
        if (turn % 2 == 0) {
            player_turn();
        } else {
            player_turn();
        }
        std::cin.get();

        if (game_won) {
            std::cout << champion << std::endl;
            break;
        }
    }
    return 0;
}
