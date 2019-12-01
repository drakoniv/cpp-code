#include <iostream>

using namespace std;

int prompt() {
    int sel = 0;
    cout << "1: Draw letter isosceles triangle.\n"
            "2: Draw letter reverse isosceles triangle.\n"
            "3: Draw letter diamond.\n"
            "4: Draw letter candy.\n"
            "0: Exit program\n"
            "Input the type of shape you want to print, or exit program: " << endl;
    cin >> sel;
    return sel;
}

void iso(int height, int mode, int hollow) {
    int sum = ((2 * height) * ((2 * height) + 1) / 2) - ((height) * (height + 1) / 2), k =
            height - 1, j = height, counter = 0;
    char printed = 'A';
    if (mode == 1) {
        j = 2 * height - 1, k = 0, printed += height - 1;
    }

    for (int i = 0; i < sum; i++) {
        if (counter == j) {
            if (mode == 0) {
                counter = 0, j++, k--, printed++;
                cout << endl;

            } else if (mode == 1) {
                counter = 0, j--, k++, printed--;
                cout << endl;
            }
        } else if (hollow == 0) {
            counter++ < k ? cout << ' ' : cout << static_cast<char>(printed);
        } else if (hollow == 1 && ((mode == 0 && j != 2 * height - 1) || mode == 1)) {
            if (counter == j - 1 || counter == k) {
                cout << static_cast<char>(printed);
                counter++;
            } else {
                cout << ' ';
                counter++;
            }
        }
    }
}

void print(int selection) {
    int height, number = 0;
    switch (selection) {
        case 1:
            cout << "Please input the height of the isosceles triangle:";
            cin >> height;
            cout << "Please input the number of the isosceles triangle:";
            cin >> number;
            cout << endl;
            for (int i = 0; i < number; i++) {
                iso(height, 0, 0);
            }
            break;
        case 2:
            cout << "Please input the height of the letter reverse isosceles triangle:";
            cin >> height;
            cout << "Please input the number of the letter reverse isosceles triangle:";
            cin >> number;
            cout << endl;
            for (int i = 0; i < number; i++) {
                iso(height, 1, 0);
            }
            break;
        case 3:
            cout << "Please input the height of the diamond:";
            cin >> height;
            cout << "Please input the number of the diamonds:";
            cin >> number;
            cout << endl;
            for (int i = 0; i < number; i++) {
                iso(height, 0, 1);
                iso(height, 1, 1);
            }
            break;
        case 4:
            cout << "Please input the height of candy:";
            cin >> height;
            cout << "Please input the number of candies:";
            cin >> number;
            cout << endl;
            for (int i = 0; i < number; i++) {
                iso(height, 1, 0);
                iso(height, 0, 1);
                iso(height, 1, 1);
                iso(height, 0, 0);
                cout << endl;
            }
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
    }
}

int main() {
    do {
        int sel = prompt();
        if (sel != 0) { print(sel); } else { break; }
    } while (true);
    return 0;
}