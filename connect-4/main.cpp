//============================================================================
// Name        : lab4.cpp
// Author      : Huaiyang
// Version     : Lab4 COMP2011 Fall 2019
// Copyright   : COMP2011 teaching team
// Description : Text-version Connect 4 Game
// Game rules  : https://en.wikipedia.org/wiki/Connect_Four
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// board size
const int HEIGHT = 6;
const int WIDTH = 7;

// TASK 1
// drop the disc to col
// you can assume col always has space for this new disc
// mark board[row][col] with player's symbol
// return the row of the dropped disc (so you know disc location (row, col)
int drop_disc(char board[][WIDTH], int height, int width, int col, char disc) {
    int rowCounter = 0; // counter for finding the final row position of disc
    for (int i = height; i >= 0; i--) { //loop through column to find empty space
        if (board[i][col] == ' ') { rowCounter++; }
    }
    board[rowCounter - 1][col] = disc; // mark disc
    return rowCounter - 1; // return row
}

// TASK 2
// check whether the newly dropped disc at (row, col) creates 4-in-a-col
// if yes, return true
bool check_4_in_a_col(const char board[][WIDTH], int height, int width, int row, int col, char disc) {
    bool valid = false;
    int counter = 0; // 4 in a col counter
    for (int i = 0; i < height; i++) {
        if (board[i][col] == disc) { counter++; }
        else { counter = 0; } // increments if consecutive discs are the same, resets if don't
        if (counter == 4) { break; } // break if counter reaches 4
    }
    counter >= 4 ? valid = true : valid = false; // valid if 4 consecutive discs are the same
    return valid;
}

// TASK 3
// check whether the newly dropped disc at (row, col) creates 4-in-a-row
// if yes, return true
bool check_4_in_a_row(const char board[][WIDTH], int height, int width, int row, int col, char disc) {
    bool valid = false;
    int counter = 0;// 4 in a col counter
    for (int i = 0; i < width; i++) {
        if (board[row][i] == disc) { counter++; }
        else { counter = 0; } // increments if consecutive discs are the same, resets if don't
        if (counter == 4) { break; } // break if counter reaches 4
    }
    counter >= 4 ? valid = true : valid = false;// valid if 4 consecutive discs are the same
    return valid;
}

// TASK 4
// check whether the newly dropped disc at (row, col) creates 4-in-a-diagonal
// both diagonal directions count
// if yes, return true
bool check_4_in_a_diagonal(const char board[][WIDTH], int height, int width, int row, int col, char disc) {
    bool valid = false;
    int counter = 0, counter2 = 0;
    if ((col + 1) <= width - 1 || (row + 1) <= height - 1) {
        for (int i = row + 1, j = col + 1; i <= height - 1 || j <= width - 1; i++, j++) {
            if (board[i][j] == disc) {
                counter++;
            } else { break; }
        }
    }

    if ((col - 1) >= 0 || (row - 1) >= 0) {
        for (int i = row - 1, j = col - 1; i >= 0 || j >= 0; i--, j--) {
            if (board[i][j] == disc) {
                counter2++;
            } else { break; }
        }
    }
    (counter + counter2 == 3) ? valid = true : valid = false;

    if (!valid) {
        counter = 0, counter2 = 0;
        if ((col + 1) <= width - 1 || (row - 1) >= 0) {
            for (int i = row - 1, j = col + 1; i >= 0 || j <= width - 1; i--, j++) {
                if (board[i][j] == disc) {
                    counter++;
                } else { break; }
            }
        }

        if ((col - 1) >= 0 || (row + 1) <= height - 1) {
            for (int i = row + 1, j = col - 1; i <= height - 1 || j >= 0; i++, j--) {
                if (board[i][j] == disc) {
                    counter2++;
                } else { break; }
            }
        }
        (counter + counter2 == 3) ? valid = true : valid = false;
    }
    return valid;
}

// print game board
void print_board(const char board[][WIDTH], int height, int width) {

    for (int row = 0; row < height; row++) {
        cout << row << '|';
        for (int col = 0; col < width; col++)
            cout << board[row][col] << '|';
        cout << endl;
    }

    for (int i = 0; i <= 2 * width + 1; i++)
        cout << '=';
    cout << endl;
    cout << "  ";

    for (int i = 0; i < width; i++) {
        cout << i << ' ';
    }
    cout << endl << endl;
}

// suppose player chooses to drop the disc to col
// validate whether the disc can be dropped
// if yes, return true
bool check_drop_valid(const char board[][WIDTH], int height, int width, int col) {
    // validate whether col is within board
    if (col < 0 || col >= width) {
        cout << "Board column should be [0, width - 1]" << endl;
        cout << "Please re-enter..." << endl;
        return false;
    }
    // validate if the selected column is full
    if (board[0][col] != ' ') {
        cout << "Column " << col << " is full. Please re-enter..." << endl;
        return false;
    }
    // valid input
    return true;
}

// check whether the game board is full
// simply check whether row 0 is full is good enough
// if yes, return true
bool check_board_full(const char board[][WIDTH], int height, int width) {
    for (int j = 0; j < width; j++)
        if (board[0][j] == ' ')
            return false;
    return true;
}

// check whether a dropped disc triggers the finish of the game
// if yes, e.g. a player wins, or game draws, return true
bool check_game_over(const char board[][WIDTH], int height, int width, int row, int col, char disc) {
    if (check_4_in_a_col(board, height, width, row, col, disc) ||
        check_4_in_a_row(board, height, width, row, col, disc) ||
        check_4_in_a_diagonal(board, height, width, row, col, disc)) {
        cout << "Player " << disc << " wins!" << endl;
        return true;
    }

    if (check_board_full(board, height, width)) {
        cout << "Draw!" << endl;
        return true;
    }

    return false;
}

// connect 4 game
int main() {
    cout << "***************" << endl;
    cout << "Connect 4 Game" << endl;
    cout << "***************" << endl << endl;

    // game board setup

    // row = 0: top row; row = height-1: bottom row
    // col = 0: leftmost col, col = width-1: rightmost col
    char board[HEIGHT][WIDTH];
    // position of the player's disc
    int row, col;
    char disc; // 2 players, one uses 'x', the other uses 'o'
    bool game_over = false;

    // game initialization
    for (int row = 0; row < HEIGHT; row++)
        for (int col = 0; col < WIDTH; col++)
            board[row][col] = ' ';

    int game_mode = 0;
    cout << "Please select game mode: 0. playing mode 1. debug mode." << endl;
    cin >> game_mode;
    if (game_mode == 1) {
        board[5][0] = 'x';
        board[2][1] = 'x';
        board[4][1] = 'x';
        board[2][2] = 'x';
        board[3][2] = 'x';
        board[4][2] = 'x';
        board[4][3] = 'x';
        board[4][5] = 'x';

        board[3][1] = 'o';
        board[5][1] = 'o';
        board[5][2] = 'o';
        board[3][3] = 'o';
        board[5][3] = 'o';
        board[5][5] = 'o';
        board[5][6] = 'o';
        // board[][] = 'x';
        disc = 'x';  // 'x' first
    } else {
        srand(time(NULL));
        int whogofirst = rand() % 2; //pick random player to start
        disc = (whogofirst == 0 ? 'x' : 'o');
    }

    cout << "Game start!" << endl << endl;
    print_board(board, HEIGHT, WIDTH);

    // game loop
    do {
        cout << "It's player " << disc << "'s turn. Enter the column to drop your disc:" << endl;
        // select a col to drop the disc
        // input validation enforced
        do {
            cin >> col;
        } while (!check_drop_valid(board, HEIGHT, WIDTH, col));

        // grab the row location of the dropped disc
        row = drop_disc(board, HEIGHT, WIDTH, col, disc);
        // print updated board
        print_board(board, HEIGHT, WIDTH);
        // check whether the player wins
        game_over = check_game_over(board, HEIGHT, WIDTH, row, col, disc);
        // swap player
        disc = (disc == 'x' ? 'o' : 'x');
    } while (!game_over);

    cout << "game over!" << endl;
}