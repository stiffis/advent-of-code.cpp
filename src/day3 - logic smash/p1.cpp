#include <fstream>
#include <iostream>
#include <string>

long long qzz1(const std::string &linea) {
    char max_val = linea[0];
    int position = 0;
    for (int i = 1; i <= linea.size() - 1; i++) {
        if (linea[i] > max_val) {
            max_val = linea[i];
            position = i;
        }
    }
    if (position == linea.size() - 1) {
        char max2 = linea[0];
        for (int i = 1; i <= linea.size() - 2; i++) {
            if (linea[i] > max2) {
                max2 = linea[i];
            }
        }
        std::string res;
        res += max2;
        res += linea[position];
        return std::stoll(res);
    }
    char max3 = linea[position + 1];

    for (int i = position + 2; i <= linea.size() - 1; i++) {
        if (linea[i] > max3) {
            max3 = linea[i];
        }
    }
    std::string res;
    res += linea[position];
    res += max3;
    return std::stoll(res);
}

int main() {
    std::ifstream input("input");

    std::string line;
    long long sum = 0;
    while (std::getline(input, line)) {
        sum += qzz1(line);
    }

    std::cout << "General sum: " << sum << std::endl;
    input.close();
    return 0;
}
