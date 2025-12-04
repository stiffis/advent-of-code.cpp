#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool is_double_rep(std::string n) {
    if (n.size() % 2 != 0)
        return false;
    int half = n.size() / 2;
    std::string a = n.substr(0, half);
    std::string b = n.substr(half);
    return a == b;
}

long long sum_range(std::string range) {
    long long sum_rang = 0;
    size_t pos = range.find('-');
    std::string a = range.substr(0, pos);
    std::string b = range.substr(pos + 1);
    long long A = stoll(a);
    long long B = stoll(b);
    for (long long i = A; i <= B; i++) {
        if (is_double_rep(std::to_string(i))) {
            sum_rang += i;
        }
    }
    return sum_rang;
}

int main() {
    std::ifstream input("input");

    long long res = 0;
    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string range;
        while (std::getline(ss, range, ',')) {
            res += sum_range(range);
        }
    }

    std::cout << "Sum of ID's: " << res << std::endl;
    input.close();
    return 0;
}
