#!/usr/bin/env perl
use strict;
use warnings;
use Scalar::Util qw(looks_like_number);
our (@board) = (
    ["-", "-", "-"],
    ["-", "-", "-"],
    ["-", "-", "-"]
);

my $turn = 1;
my $game_won = 0;

my $player1 = "X";
my $player2 = "O";

sub print_board {
    for my $row (@board) {
        for my $col (@$row) {
            print "$col ";
        }
        print "\n";
    }
    return 0;
};

sub is_number {
    my ($number) = @_;
    my $is_number = looks_like_number($number);
    return $is_number ? 1 : 0;
};

sub next_turn {
    if ($turn == 1) {
        $turn = 2;
    } else {
        $turn = 1;
    }
};

sub get_turn {
    if ($turn % 2 == 0) {
        return $player2;
    } else {
        return $player1;
    }
};

sub set_board {
    my ($input) = @_;

    if ($input == "1") {
        if ($board[0][0] eq '-') {
            $board[0][0] = get_turn();
            print "Player has chosen the top left corner.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "2") {
        if ($board [0][1] eq '-') {
            $board[0][1] = get_turn();
            print "Player has chosen the top middle.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "3") {
        if ($board [0][2] eq '-') {
            $board[0][2] = get_turn();
            print "Player has chosen the top right.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "4") {
        if ($board [1][0] eq '-') {
            $board[1][0] = get_turn();
            print "Player has chosen the mid left.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "5") {
        if ($board [1][1] eq '-') {
            $board[1][1] = get_turn();
            print "Player has chosen the mid middle.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "6") {
        if ($board [1][2] eq '-') {
            $board[1][2] = get_turn();
            print "Player has chosen the mid right.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "7") {
        if ($board [2][0] eq '-') {
            $board[2][0] = get_turn();
            print "Player has chosen the bottom left.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "8") {
        if ($board [2][1] eq '-') {
            $board[2][1] = get_turn();
            print "Player has chosen the bottom middle.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    } elsif ($input == "9") {
        if ($board [2][2] eq '-') {
            $board[2][2] = get_turn();
            print "Player has chosen the bottom right.\n";
        } else {
            print "That space is already taken.\n";
            return 0;
        }
    }
    return 1;
}

sub check_win {
    my ($input) = @_;

    if ($board[0][0] eq $board[0][1] && $board[0][1] eq $board[0][2] && $board[0][2] ne '-') {
        print "Game over!\n";
    }
};

sub player_turn {
    print_board();
    print "Please enter a number between 1-9: ";
    my $input = <STDIN>;
    print join("User input= ",  $input), "\n";
    if (is_number($input)) {
        my $set = set_board($input);
        if ($set) {
            #check_win();
            next_turn();
        } else {
            player_turn();
        }
    } else {
        print "Invalid input. Please enter a number between 1-9: \n";
        player_turn();
    }
};

while (1) {
    if ($turn % 2 == 1) {
        print "Player 1's turn\n";
    } else {
        print "Player 2's turn\n";
    }
    player_turn();

    if ($game_won) {
        print "Player $turn won!\n";
        last;
    }
};