#!/bin/bash
#__   __   ___     ____ _____   _____ ___ ____   _____  _    ____   _____ ___  _____
#\ \ / /  ( _ )   / ___|_   _| |_   _|_ _/ ___| |_   _|/ \  / ___| |_   _/ _ \| ____|
# \ V /   / _ \/\ \___ \ | |     | |  | | |       | | / _ \| |       | || | | |  _|
#  | |   | (_>  <  ___) || |     | |  | | |___    | |/ ___ \ |___    | || |_| | |___
#  |_|    \___/\/ |____/ |_|     |_| |___\____|   |_/_/   \_\____|   |_| \___/|_____|
# Title:         Bash tic tac toe
# Original Date: 2023-01-01
# Version:       2023-01-01
game=true
board=(
    "-" "-" "-"
    "-" "-" "-"
    "-" "-" "-"
)
player="X"

print_board() {
    str_board=""
    for i in "${!board[@]}"
    do
        str_board+="${board[$i]}"
        if [ $i -eq 2 ] || [ $i -eq 5 ] || [ $i -eq 8 ]
        then
            str_board+="\n"
        fi
    done
    echo -e $str_board
}

player_turn() {
    echo "Turn $player: Please select a number between 1 - 9"
    read input
    re='^[0-9]+$'
    if [[ $input =~ $re ]]
    then
        set_turn $input
    else
        echo "Invalid input"
    fi
}

set_turn() {
    correct_pos=$(($1-1))
    if [ ${board[$correct_pos]} == "-" ]
    then
        board[correct_pos]=$player
    else
        echo "invalid move"
    fi
    print_board
}

next_turn() {
    if [ $player == "X" ]
    then
        player="O"
    else
        player="X"
    fi
}

check_win() {
    win_conditions=(
        0 1 2
        3 4 5
        6 7 8
        0 3 6
        1 4 7
        2 5 8
        0 4 8
        2 4 6
    )
    for (( i=0; i<24; ))
    do
        a=${win_conditions[$i]}
        b=${win_conditions[$(($i+1))]}
        c=${win_conditions[$(($i+2))]}
        if 
            [ ${board[$a]} ==  ${board[$b]} ] &&
            [ ${board[$b]} ==  ${board[$c]} ] &&
            ! [ ${board[$c]} ==  "-" ]
        then
            game=false
        fi
        i=$(($i+3))
    done
}

while [ $game = true ]
do
    print_board
    player_turn
    check_win
    if [ $game == false ]
    then
        echo "$player has won"
    fi
    next_turn
done

