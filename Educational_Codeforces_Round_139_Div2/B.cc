// B. Notepad#
// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You want to type the string , consisting of  lowercase Latin letters, using your favorite text editor Notepad#.

// Notepad# supports two kinds of operations:

// append any letter to the end of the string;
// copy a continuous substring of an already typed string and paste this substring to the end of the string.
// Can you type string  in strictly less than  operations?

// Input
// The first line contains a single integer  (1104)  the number of testcases.

// The first line of each testcase contains a single integer  (12105)  the length of the string .

// The second line contains a string , consisting of  lowercase Latin letters.

// The sum of  doesn't exceed 2105 over all testcases.

// Output
// For each testcase, print "YES" if you can type string  in strictly less than  operations. Otherwise, print "NO".

// Example
// inputCopy
// 6
// 10
// codeforces
// 8
// labacaba
// 5
// uohhh
// 16
// isthissuffixtree
// 1
// x
// 4
// momo
// outputCopy
// NO
// YES
// NO
// YES
// NO
// YES

#include <iostream>

std::string solution(int n, std::string str) {
    if (n >= 1353) {
        return "YES";
    }
    // search for duplicated pair
    for (int i = 0; i < n - 1; i++) {
        std::string substring = str.substr(i, 2);
        if (std::string::npos != str.find(substring, i + 2)) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    std::string num;
    std::getline(std::cin, num);

    std::string line1;
    std::string line2;
    for (int i = 0; i < stoi(num); i++) {
        std::getline(std::cin, line1);
        std::getline(std::cin, line2);
        std::cout << solution(stoi(line1), line2) << std::endl;
    }
    return 0;
}