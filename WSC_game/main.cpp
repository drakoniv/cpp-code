#include <iostream>
//items definition inside of string
#define wLeft items[0]
#define wRight items[28]
#define sLeft items[2]
#define sRight items[30]
#define cLeft items[4]
#define cRight items[32]

using namespace std; //namespace definition

bool win = false;
char item;
string boat = "boat                            ";
string items = "w s c                            ";
int position = 0;
int showEnd = 1;//global var init

void print(void) {
    cout << "Left  --------------------  Right" << endl << items << endl << boat << endl;
    if (showEnd == 1) { cout << "Item to carry (w: wolf, s: sheep, c: cabbage, n: nothing):" << endl; } //show prompt
}

void changePos() { //change position function
    bool valid = false;
    do { //repeat game until player don't want to play again
        switch (item) {
            case 'w' :
            case 'W':
                if (wLeft != ' ' && position == 0) {
                    wRight = 'w';
                    wLeft = ' ';
                    valid = true;
                } // switch wolf position if valid
                else if (wRight != ' ' && position == 1) {
                    wLeft = 'w';
                    wRight = ' ';
                    valid = true;
                }
                else {
                    cout << "Wolf is on the other side!" << endl;
                    valid = false;
                }
                break;
            case 's' :
            case 'S':
                if (sLeft != ' ' && position == 0) {
                    sRight = 's';
                    sLeft = ' ';
                    valid = true;
                } // switch sheep position if valid
                else if (sRight != ' ' && position == 1) {
                    sLeft = 's';
                    sRight = ' ';
                    valid = true;
                }
                else {
                    cout << "Sheep is on the other side!" << endl;
                    valid = false;
                }
                break;
            case 'c' :
            case 'C':
                if (cLeft != ' ' && position == 0) {
                    cRight = 'c';
                    cLeft = ' ';
                    valid = true;
                } //switch cabbage position if valid
                else if (cRight != ' ' && position == 1) {
                    cLeft = 'c';
                    cRight = ' ';
                    valid = true;
                }
                else {
                    cout << "Cabbage is on the other side!" << endl;
                    valid = false;
                }
                break;
            case 'n' :
            case 'N':
                valid = true;
                break;
            default:
                cout << "input not valid!" << endl;
                valid = false;
                break; // invalid input
        }
        if (!valid) { // ask user again if input is invalid
            cout << "Item to carry (w: wolf, s: sheep, c: cabbage, n: nothing):" << endl;
            cin >> item;
        }
    } while (!valid);
    if (position == 1) {
        boat = "boat                            ";
        position = 0;
    }
    else {
        boat = "                            boat";
        position = 1;
    } //switch boat position
}

void reset() {//reset function
    char retry;
    cout << "Play Again? press y to reset game or other keys to leave..."
         << endl; // ask player if they want to continue
    cin >> retry; // get user input
    if (retry == 'y' || retry == 'Y') {
        wRight = sRight = cRight = ' ';  // reset item position
        wLeft = 'w';
        sLeft = 's';
        cLeft = 'c';
        boat = "boat                            ";
        position = 0; // reset boat position
        win = false; // make loop continue
        showEnd = 1;
        cout << "Game Start!" << endl;
        print();
    } //print initial game state
    else {
        cout << "Thanks for playing!";
        win = true;
    } // end game if player press key other than y
}

void check() {//check function
    if ((wLeft == 'w' && sLeft == 's' && position == 1) ||
        (wRight == 'w' && sRight == 's' && position == 0)) { // wolf eat sheep
        showEnd = 0;
        print();
        cout << "The wolf has eaten the sheep. You lose!" << endl;
        reset();
    } else if ((sLeft == 's' && cLeft == 'c' && position == 1) ||
               (sRight == 's' && cRight == 'c' && position == 0)) { // sheep eat cabbage
        showEnd = 0;
        print();
        cout << "The sheep has eaten the cabbage. You lose!" << endl;
        reset();
    } else if (wRight == 'w' && sRight == 's' && cRight == 'c') { // win condition
        showEnd = 0;
        print();
        cout << "All items are at the right side. You win!" << endl;
        reset();
    } else { print(); }
}

int main() {
    cout << "****************************" << endl << "Wolf, Sheep and Cabbage Game" << endl
         << "****************************" << endl << "Press enter to start" << endl; //Game header
    cin.ignore(); // press enter to continue
    cout << "Game Start!" << endl;
    print(); //show game initial state
    do {
        cin >> item;
        changePos();
        check();
    }
    while (!win); // initiate game
    return 0;
}