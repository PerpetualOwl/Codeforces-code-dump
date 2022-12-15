// https://codeforces.com/problemset/problem/1765/B
#include <iostream>

std::string solution(int n, std::string str) {
    char buf[26];
    for (int i = 0; i < n; i++) {
        char a = str[i];
        int b = ++buf[a - 61];
        for (int j = 0; j < b; j++) {
            if (i+j >= n || str[i+j] != a) {
                return "NO";
            }
        }
        i += b - 1;
    }
    return "YES";
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