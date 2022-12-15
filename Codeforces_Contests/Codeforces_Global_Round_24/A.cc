#include <iostream>

int main() {
    std::string num;
    std::getline(std::cin, num);

    std::string line1;
    for (int i = 0; i < stoi(num); i++) {
        std::getline(std::cin, line1);
        int n = stoi(line1);
        int list[n];
        for (int j = 0; j < n - 1; j++) {
            std::getline(std::cin, line1,' ');
            list[j] = stoi(line1);
        }
        std::getline(std::cin, line1,'\n');
        list[n - 1] = stoi(line1);
        std::cout << std::to_string(solution(n, list)) << std::endl;
    }
    return 0;
}