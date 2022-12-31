#include <iostream>
void player_turn();

std::string board[9] = {
    "-", "-", "-",
    "-", "-", "-",
    "-", "-", "-"
};

bool turn = true;

std::string champion;
bool game_won = false;

void print_board() {
    for (int i = 0; i < 9; i++) {
        std::cout << board[i];
        if (i == 2 || i == 5 || i == 8) {
            std::cout << std::endl;
        };
    }
}

int is_number(std::string input) {
    char c = input[0];
    if (std::isdigit(c) == 0) return false;
    if (c < '1' || c > '9') return false;
    return true;
}

int get_turn() {
    return (turn) ? 88 : 79;
}

void next_turn() {
    turn = !turn;
}

void check_win() {
    int win_conditions[8][3] = {
        {0 , 1, 2},
        {3 , 4, 5},
        {6 , 7, 8},
        {0 , 3, 6},
        {1 , 4, 7},
        {2 , 5, 8},
        {0 , 4, 8},
        {2 , 4, 6},
    };
    for (int* positions : win_conditions) {
        if (
            (board[positions[0]] == board[positions[1]]) &&
            (board[positions[1]] == board[positions[2]]) &&
            (board[positions[2]] != "-")
        ) {
            game_won = true;
        }
    }
}

void set_board(int input) {
    int correct_pos = input - 1;
    if (board[correct_pos] != "-") {
        std::cout << "Invalid move" << std::endl;
        return;
    }

    board[correct_pos] = (char)get_turn();
    check_win();
}

void player_turn() {
    print_board();
    std::string input = "";
    std::cout << "Please enter a number between 1 and 9: " << std::endl;
    std::cin >> input;
    if (is_number(input)) {
        set_board(std::stoi(input));
    } else {
        std::cout << "Invalid input" << std::endl;
        player_turn();
    }
}

int main() {
    while (true) {
        std::cout << "Player " << turn << " turn: " << std::endl;
        player_turn();
        std::cin.get();

        if (game_won) {
            std::cout << (char)get_turn();
            printf("Player %c wins!", (char)get_turn());
            break;
        }
        next_turn();
    }
    return 0;
}
