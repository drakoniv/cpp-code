#include <iostream>
#include "test.h"
int main() {
    int height = 4*120;
    int counter = 0;
    int counter2 = 0;
    for( int i=0; i<height; i++) {
        if(counter < counter2) {
            std::cout << "*";
        } else {
            std::cout << " ";
        }

        if( i % 4 == 0) {
            counter = 0;
        } else {
            counter++;
        }

        if(i % 120 == 0) {
            counter2++;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    test::mgoi();


    return 0;
}