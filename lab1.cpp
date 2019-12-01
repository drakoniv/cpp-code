#include <iostream>
using namespace std;


int main() {
    /**
     * Part 1
     *
     * After you have fixed all syntax error, you can run the program and you should see
     *
     * "Hello student. May I know how many years have you been HKUST?"
     *
     * Then you are prompted to input. You should have different replies when you enter 1, 2 and 4.
     *
     */
    int year;
    cout << "Hello student. May I know how many years have you been HKUST?" << endl;
    cin >> year;
    if (year == 1)
        cout << "Welcome to UST. I guess you are either an exchange or a direct entry student." << endl;
    else if (2 <= year && 3 >= year)
        cout << "I am not sure if you are a CSE major student. If not, you might want to take CSE as your second major"
             << endl;
    else
        cout << "It is odd, but please enjoy the course too" << endl;

    /**
     * Part 2
     *
     * When you have finished Part 1, take away the inline comment symbol // below
     * 
     * After you have fixed Part 2, it should show the value of i from 0 to 9 and
     * state: The va lue of i after the loop is: 10
     */
    int i;
    for (i = 0; i < 10; i++) {
        cout << "i = " << i << ",";
    }

    cout << endl << "The value of i after the loop is: " << i << endl;

    /**
     * Part 3
     *
     * When you have finished Part 2, take away the inline comment symbol // below
     *
     * After fixing this part, your program should prompt you to enter a character and it gives
     * different result if you enter small L `l` and special symbol like `_`. 
     */
    char x;
    cout << "Please enter a character (a-z or A-Z):" << endl;
    cin >> x;

    if (x == 'I' || x == 'O' || x == 'l') {
        cout << "This letter " << x << " looks similar to a numeric character." << endl;
        cout << "It is not a proper variable name although you can use it." << endl;
    } else if ((x < 'A' || x > 'Z') && (x < 'a' || x > 'z')) {
        cout << "You are not typing a English character!" << endl;
    }
}



