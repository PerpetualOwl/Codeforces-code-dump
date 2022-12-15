#include <iostream>
#include <vector>
#include <string>

unsigned long long solution(unsigned long long length, int* list) {
    int min = list[0];
    int max = list[0];
    for (int i = 0; i < length; i++) {
        if (list[i] < min) min = list[i];
        if (list[i] > max) max = list[i];
    }
    if (min == max) {
        return (length * (length - 1));
    }
    unsigned long long mincount = 0;
    unsigned long long maxcount = 0;
    for (int i = 0; i < length; i++) {
        if (list[i] == min) mincount++;
        if (list[i] == max) maxcount++;
    }
    return (mincount * maxcount) << 1;
}

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
