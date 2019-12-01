//
// Created by drako on 9/10/2019.
//

#ifndef RAT_TEST_H
#define RAT_TEST_H


#include <iostream>

class test {

public:
    static int mgoi() {
        const double A = 4.0;
        const double B = 3.0;
        const double C = 2.0;
        const double D = 1.0;
        const double F = 0.0;

        int credit = 0;
        float total_grade_points = 0.0f;
        char grade = 0;
        do {
            std::cout << "No. of credits of your course: " << std::endl;
            std::cin >> credit;
            std::cout << "your grade:  " << std::endl;
            std::cin >> grade;
            switch(grade) {
                case 'A':
                    total_grade_points += credit *4; break;
                case 'B':
                    total_grade_points += credit *3; break;
                case 'C':
                    total_grade_points += credit *2; break;
                case 'D':
                    total_grade_points += credit *1; break;
                case 'F':
                    total_grade_points += credit *0; break;
                default:
                    total_grade_points -= credit ; break;
            }
            std::cout << total_grade_points << std::endl;
        } while(credit != 0);
    }
};


#endif //RAT_TEST_H
