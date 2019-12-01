/*
 * main.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: kevinw
 */

#include <iostream>
#include <cstring>
using namespace std;

const int ARRAY_SIZE = 12;
const char POTION = 'o';
const char RIM = 'T';
const char WALL = '*';
const char EMPTY = ' ';

enum TASK {CLEANUP, WARMUP_FILL, SIMPLE_FILL, ADVANCED_FILL};
void print_array(const char array[][ARRAY_SIZE+1]) {
    cout << "  ";
    for (int j = 0; j < ARRAY_SIZE; j++)
        cout << j % 10;
    cout << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << i % 10 << " ";
        cout << array[i] << endl;
    }
}

void detect_rim(char array[ARRAY_SIZE][ARRAY_SIZE+1], int& rimCol, int& rimLevel, int& toggleStatus , int row = 0 , int col = 0) {
    if( row >= 0 ) {
        if ( col < ARRAY_SIZE + 1 ) {
            if(array[row][col] == RIM && rimLevel == -1 && toggleStatus == 0 && rimCol == -1) {

                rimLevel = row;
                rimCol = col;
                toggleStatus = 1;
            }
            detect_rim(array, rimCol, rimLevel, toggleStatus, row, col+1);
        } else{
            return ;
        }
        if(col == 0) {
            detect_rim(array, rimCol, rimLevel, toggleStatus, row - 1, col);
        }
    } else{
        return ;
    }
}

void detect_rim_right(char array[ARRAY_SIZE][ARRAY_SIZE+1], int& rimCol, int& rimLevel, int& toggleStatus , int row = 0 , int col = ARRAY_SIZE) {
    if( row >= 0 ) {
        if ( col >= 0) {
            if(array[row][col] == RIM && rimLevel == -1 && toggleStatus == 0 && rimCol == -1) {
                rimLevel = row;
                rimCol = col;
                toggleStatus = 1;
            }
            detect_rim_right(array, rimCol, rimLevel, toggleStatus, row, col-1);
        } else{
            return ;
        }
        if(col == ARRAY_SIZE) {
            detect_rim_right(array, rimCol, rimLevel, toggleStatus, row - 1, col);
        }
    } else{
        return ;
    }
}

void detect_spill (char array[ARRAY_SIZE][ARRAY_SIZE+1], int& spilled, int row = 0, int col = 0) {
    if (spilled == 0) {
        if (row < ARRAY_SIZE && col == 0 && array[row][col] != POTION) {
            detect_spill(array, spilled, row + 1, 0);
        } else if (array[row][col] == POTION) {
            spilled = 1;
            return;
        } else {
            if (col < ARRAY_SIZE - 1 && array[row][col] != POTION) {
                detect_spill(array, spilled, ARRAY_SIZE, col + 1);
            } else if (array[row][col] == POTION) {
                spilled = 1;
                return;
            } else {
                if (row >= 0 && array[row][col] != POTION) {
                    detect_spill(array, spilled, row - 1, ARRAY_SIZE - 1);
                } else if (array[row][col] == POTION) {
                    spilled = 1;
                    return;
                } else {
                    return;
                }
            }

        }
    }
}

void detect_spill_rim (char array[ARRAY_SIZE][ARRAY_SIZE+1], int& spilled, int row = 0, int col = 0){
    if (spilled == 0) {
        int leftRimCol = -1;
        int rimLevel = -1;
        int toggle = 0;
        detect_rim(array, leftRimCol, rimLevel, toggle, ARRAY_SIZE - 1);
        int rightRimCol = -1;
        int rightrimLevel = -1;
        int righttoggle = 0;
        detect_rim_right(array, rightRimCol, rightrimLevel, righttoggle, ARRAY_SIZE - 1);
        if ((col < leftRimCol || col > rightRimCol) && array[row][col] != POTION && col < ARRAY_SIZE + 1) {
            detect_spill_rim(array, spilled, rimLevel, col + 1);
        } else if ((col < leftRimCol || col > rightRimCol) && array[row][col] == POTION) {
            spilled = 1;
            return;
        } else if(col >= leftRimCol && col <= rightRimCol){
            detect_spill_rim(array,spilled,rimLevel,col+1);
        } else {
            return;
        }

    }
}
int cleanup(char array[ARRAY_SIZE][ARRAY_SIZE+1], int row = 0, int col = 0) {
// Don't forget to return!
    if (row >= 0 && row < ARRAY_SIZE && col >= 0 && col < ARRAY_SIZE + 1) {
        if (array[row][col] == POTION) {
            array[row][col] = EMPTY;
            return 1 + cleanup(array, row + 1, col) + cleanup(array, row, col + 1);
        } else {
            return cleanup(array, row + 1, col) + cleanup(array, row, col + 1);
        }
    } else {
        return 0;
    }
}

void warmup_fill(char array[][ARRAY_SIZE+1], int row, int col, int level) {
    if (row >= 0 && col >= 0 && row < ARRAY_SIZE && col < ARRAY_SIZE + 1) {
        if (array[row][col] != POTION && array[row][col] != WALL && array[row][col] != RIM && row + 1 <= ARRAY_SIZE &&
            col + 1 < ARRAY_SIZE + 1) {
            warmup_fill(array, row + 1, col, level);
        } else {
            return;
        }

        if (row >= level) {
            if (array[row][col] != POTION && array[row][col] != WALL && array[row][col] != RIM) {
                array[row][col] = POTION;
            }
            warmup_fill(array, row - 1, col, level);
            warmup_fill(array, row, col + 1, level);
            warmup_fill(array, row, col - 1, level);
        }

    } else {
        return;
    }
}


void simple_fill(char array[][ARRAY_SIZE+1], int row, int col) {
    if (row >= 0 && col >= 0 && row < ARRAY_SIZE && col < ARRAY_SIZE + 1) {
        if (array[row][col] != POTION && array[row][col] != WALL && array[row][col] != RIM && row + 1 <= ARRAY_SIZE &&
            col + 1 < ARRAY_SIZE + 1) {
            simple_fill(array, row + 1, col);
        } else {
            return;
        }
        if (array[row][col] != POTION && array[row][col] != WALL && array[row][col] != RIM &&
            (array[row + 1][col] == POTION || array[row + 1][col] == WALL) &&
            array[row + 1][col + 1] != RIM && array[row + 1][col - 1] != RIM) {
            array[row][col] = POTION;

            simple_fill(array, row - 1, col);
            simple_fill(array, row, col + 1);
            simple_fill(array, row, col - 1);
        }


    } else {
        return;
    }
}


int advanced_fill(char array[][ARRAY_SIZE+1], int row, int col) {
// Don't forget to return!
// Don't forget to return!
    int spilled = 0;

    int leftRimCol = -1;
    int rimLevel = -1;
    int toggle = 0;
    detect_rim(array, leftRimCol, rimLevel, toggle, ARRAY_SIZE - 1);
    int rightRimCol = -1;
    int rightrimLevel = -1;
    int righttoggle = 0;
    detect_rim_right(array, rightRimCol, rightrimLevel, righttoggle, ARRAY_SIZE - 1);
    int test =0;
    if(row == 0 && (col < leftRimCol ||col > rightRimCol)) {
        test = 1;
    }

    if (row >= 0 && col >= 0 && row < ARRAY_SIZE && col < ARRAY_SIZE + 1 && test == 0) {
        if (array[row][col] != POTION && array[row][col] != WALL && array[row][col] != RIM && row + 1 <= ARRAY_SIZE &&
            col + 1 < ARRAY_SIZE + 1) {
            advanced_fill(array, row + 1, col);
        } else {
            return 0;
        }
        int leftRimCol = -1;
        int rimLevel = -1;
        int toggle = 0;
        detect_rim(array, leftRimCol, rimLevel, toggle, row);

        if (row >= rimLevel && rimLevel != -1) {
            if (array[row][col] != POTION && array[row][col] != WALL && array[row][col] != RIM) {
                array[row][col] = POTION;

            }
            advanced_fill(array, row - 1, col);
            advanced_fill(array, row, col + 1);
            advanced_fill(array, row, col - 1);
        }

    } else {
        return 0;
    }

    if ( row == 0) {
        detect_spill(array, spilled);
        if(spilled == 0) {
            detect_spill_rim(array, spilled);
        }
        if(spilled == 1)
            cleanup(array);
    }
    return 0;
}



void fill(int algorithm, char array[][ARRAY_SIZE+1], int row, int col) {
    cout << "Before Water is filled" << endl;
    print_array(array);
    int level;
    switch (algorithm) {
        case CLEANUP:
            cleanup(array);
            break;
        case WARMUP_FILL:
            cout << "Please help me mark the level:" << endl;
            cin >> level;
            warmup_fill(array, row, col, level);
            cout << "Warmup Fill" << endl;
            break;
        case SIMPLE_FILL:
            simple_fill(array, row, col);
            cout << "Simple Fill" << endl;
            break;
        case ADVANCED_FILL:
            advanced_fill(array,row,col);
            cout << "Advanced Fill" << endl;
            break;
    }
    print_array(array);
}


int main() {
    char test_tube[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            "     T T    ",
            "     * *    ",
            "     * *    ",
            "     * *    ",
            "     * *    ",
            "     ***    ",
            "            ",
            "            "
    };


    char two_tubes[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "     T T    ",
            "     ***    ",
            "            ",
            "     T T    ",
            "     * *    ",
            "     * *    ",
            "     * *    ",
            "     * *    ",
            "     ***    ",
            "            ",
            "            "
    };


    char conical_flask[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            "     T T    ",
            "     * *    ",
            "     * *    ",
            "    *   *   ",
            "   *     *  ",
            "  ********* ",
            "            ",
            "            "
    };


    char broken_tube[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            "     T T    ",
            "     * *    ",
            "     * *    ",
            "     * *    ",
            "     * *    ",
            "            ",
            "            ",
            "            "
    };

    char broken_flask[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            "     T T    ",
            "     * *    ",
            "     * *    ",
            "    *   *   ",
            "         *  ",
            "  ********* ",
            "            ",
            "            "
    };
    char beaker[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            "  T    T    ",
            "  *    *    ",
            "  *    *    ",
            "  *    *    ",
            "  *    *    ",
            "  ******    ",
            "            ",
            "            "
    };



    char flask[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "    T T     ",
            "    * *     ",
            "    * *     ",
            "  **   **   ",
            " *       *  ",
            " *       *  ",
            " *       *  ",
            "  *     *   ",
            "   *****    ",
            "            ",
            "            "
    };


    char up_and_down[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            " T T        ",
            " * * *******",
            " * * *   * *",
            " * *** * * *",
            " *     *   *",
            " ********* *",
            " *         *",
            " ***********"
    };

    char broken_u_flask[ARRAY_SIZE][ARRAY_SIZE+1] = {
            "            ",
            "            ",
            "            ",
            "            ",
            "    T T     ",
            "    * * *  *",
            "    * ***  *",
            "   *      * ",
            "  *     **  ",
            " *********  ",
            "            ",
            "            "
    };


    int opt;
    while (true) {
        cout << "Enter 0 (cleanup), 1 (warmup), 2 (simple), 3 (advanced) to select your algorithm, or other value to quit the program:" << endl;
        cin >> opt;
        if (opt < 0 || opt > 3)
            return 0;

        fill(opt, test_tube, 0, 6);
        fill(opt, conical_flask, 0, 6);
        fill(opt, flask,0,5);
        fill(opt, up_and_down, 0, 2);
        if (opt != ADVANCED_FILL)
            fill(opt, two_tubes, 0, 6);
        else
            cout << "Not for advanced_fill" << endl;
        if (opt != SIMPLE_FILL && opt != WARMUP_FILL)
            fill(opt, broken_flask, 0, 6);
        else
            cout << "Not for warmup_fill and simple_fill" << endl;
        if (opt != SIMPLE_FILL && opt != WARMUP_FILL)
            fill(opt, broken_tube, 0, 6);
        else
            cout << "Not for warmup_fill and simple_fill" << endl;
        if (opt != SIMPLE_FILL && opt != WARMUP_FILL)
            fill(opt, beaker, 0, 4);
        else
            cout << "Not for warmup_fill and simple_fill" << endl;
        if (opt != SIMPLE_FILL && opt != WARMUP_FILL)
            fill(opt, broken_u_flask,0,5);
        else
            cout << "Not for warmup_fill and simple_fill" << endl;
    }
    return 0;


}