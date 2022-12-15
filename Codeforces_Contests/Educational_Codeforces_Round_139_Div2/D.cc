// D. Lucky Chains
// time limit per test4 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// Let's name a pair of positive integers (,) lucky if the greatest common divisor of them is equal to 1 (gcd(,)=1).

// Let's define a chain induced by (,) as a sequence of pairs (,), (+1,+1), (+2,+2), , (+,+) for some integer 0. The length of the chain is the number of pairs it consists of, or (+1).

// Let's name such chain lucky if all pairs in the chain are lucky.

// You are given  pairs (,). Calculate for each pair the length of the longest lucky chain induced by this pair. Note that if (,) is not lucky itself, the chain will have the length 0.

// Input
// The first line contains a single integer  (1106)  the number of pairs.

// Next  lines contains  pairs  one per line. The -th line contains two integers  and  (1<107)  the corresponding pair.

// Output
// Print  integers, where the -th integer is the length of the longest lucky chain induced by (,) or 1 if the chain can be infinitely long.

// Example
// inputCopy
// 4
// 5 15
// 13 37
// 8 9
// 10009 20000
// outputCopy
// 0
// 1
// -1
// 79


#include <iostream>

int min(int n, int m) {
    if (n < m) {
        return n;
    }
    return m;
}

int smallestPrimeFactor(int n)
{
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
    return n;
}

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        if (a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int solution(int n, int m) {
    if (gcd(n, m) != 1) {
        return 0;
    }
    if (n % 2 == m % 2) {
        return 1;
    }
    int diff = n - m;
    if (diff < 0) diff = 0 - diff;
    if (diff == 1) {
        return -1;
    }
    int i = 1;
    diff = min(smallestPrimeFactor(diff), 8000);
    for (int i = 1; i <= diff; i++) {
        if (gcd(n + i, m + i) != 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string num;
    std::getline(std::cin, num);

    std::string line;
    std::string line2;
    for (int i = 0; i < stoi(num); i++) {
        std::getline(std::cin, line, ' ');
        std::getline(std::cin, line2, '\n');
        std::cout << std::to_string(solution(stoi(line), stoi(line2))) << std::endl;
    }
    return 0;
}