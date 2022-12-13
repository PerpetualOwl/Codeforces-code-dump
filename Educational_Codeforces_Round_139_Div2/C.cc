// C. Hamiltonian Wall
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Sir Monocarp Hamilton is planning to paint his wall. The wall can be represented as a grid, consisting of 2 rows and  columns. Initially, the wall is completely white.

// Monocarp wants to paint a black picture on the wall. In particular, he wants cell (,) (the -th cell in the -th row) to be colored black, if ,= 'B', and to be left white, if ,= 'W'. Additionally, he wants each column to have at least one black cell, so, for each , the following constraint is satisfied: 1,, 2, or both of them will be equal to 'B'.

// In order for the picture to turn out smooth, Monocarp wants to place down a paint brush in some cell (1,1) and move it along the path (1,1),(2,2),,(,) so that:

// for each , (,) and (+1,+1) share a common side;
// all black cells appear in the path exactly once;
// white cells don't appear in the path.
// Determine if Monocarp can paint the wall.

// Input
// The first line contains a single integer  (1104)  the number of testcases.

// The first line of each testcase contains a single integer  (12105)  the number of columns in the wall.

// The -th of the next two lines contains a string , consisting of  characters, where each character is either 'B' or 'W'. , is 'B', if the cell (,) should be colored black, and 'W', if the cell (,) should be left white.

// Additionally, for each , the following constraint is satisfied: 1,, 2, or both of them are equal to 'B'.

// The sum of  over all testcases doesn't exceed 2105.

// Output
// For each testcase, print "YES" if Monocarp can paint a wall. Otherwise, print "NO".

// Example
// inputCopy
// 6
// 3
// WBB
// BBW
// 1
// B
// B
// 5
// BWBWB
// BBBBB
// 2
// BW
// WB
// 5
// BBBBW
// BWBBB
// 6
// BWBBWB
// BBBBBB
// outputCopy
// YES
// YES
// NO
// NO
// NO
// YES

#include <iostream>
#define TOP 0
#define BOTTOM 1

std::string solution(int n, std::string str, std::string str2) {
    const char* top = str.c_str();
    const char* bottom = str2.c_str();
    //fprintf(stdout, "T: %s\nB:%s\n", top, bottom);
    if (top[0] == 'B') {
        bool current = TOP;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n) {
                return "YES";
            }
            if (current == TOP) {
                if (bottom[i] == 'B') {
                    current = BOTTOM;
                    if (bottom[i + 1] != 'B') {
                        break;
                    }
                } else {
                    if (top[i + 1] != 'B') {
                        break;
                    }
                }
            } else {
                if (top[i] == 'B') {
                    current = TOP;
                    if (top[i + 1] != 'B') {
                        break;
                    }
                } else {
                    if (bottom[i + 1] != 'B') {
                        break;
                    }
                }
            }
        }
    }
    if (bottom[0] == 'B') {
        bool current = BOTTOM;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n) {
                return "YES";
            }
            if (current == TOP) {
                if (bottom[i] == 'B') {
                    current = BOTTOM;
                    if (bottom[i + 1] != 'B') {
                        break;
                    }
                } else {
                    if (top[i + 1] != 'B') {
                        break;
                    }
                }
            } else {
                if (top[i] == 'B') {
                    current = TOP;
                    if (top[i + 1] != 'B') {
                        break;
                    }
                } else {
                    if (bottom[i + 1] != 'B') {
                        break;
                    }
                }
            }
        }
    }
    return "NO";
}


int main() {
    std::string num;
    std::getline(std::cin, num);

    std::string line1;
    std::string line2;
    std::string line3;
    for (int i = 0; i < stoi(num); i++) {
        std::getline(std::cin, line1);
        std::getline(std::cin, line2);
        std::getline(std::cin, line3);
        std::cout << solution(stoi(line1), line2, line3) << std::endl;
    }
    return 0;
}
