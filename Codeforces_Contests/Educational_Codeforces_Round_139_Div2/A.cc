// A. Extremely Round
// time limit per test3 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// Let's call a positive integer extremely round if it has only one non-zero digit. For example, 5000, 4, 1, 10, 200 are extremely round integers; 42, 13, 666, 77, 101 are not.

// You are given an integer . You have to calculate the number of extremely round integers  such that 1.

// Input
// The first line contains one integer  (1104)  the number of test cases.

// Then,  lines follow. The -th of them contains one integer  (1999999)  the description of the -th test case.

// Output
// For each test case, print one integer  the number of extremely round integers  such that 1.

// Example
// inputCopy
// 5
// 9
// 42
// 13
// 100
// 111
// outputCopy
// 9
// 13
// 10
// 19
// 19

#include <iostream>

int solution(int n) {
    int num = n;
    int power = 0;
    while (num >= 10) {
        num /= 10;
        power++;
    }
    return power * 9 + num;
}

int main() {
    std::string num;
    std::getline(std::cin, num);

    std::string line;
    for (int i = 0; i < stoi(num); i++) {
        std::getline(std::cin, line);
        std::cout << std::to_string(solution(stoi(line))) << std::endl;
    }
    return 0;
}