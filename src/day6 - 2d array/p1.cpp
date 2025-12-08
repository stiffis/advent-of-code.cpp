#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<long long> linetoll(const std::string &line) {
    std::vector<long long> result;
    std::stringstream ss(line);
    long long temp;
    while (ss >> temp) {
        result.push_back(temp);
    }
    return result;
}

std::vector<char> linetochars(const std::string &line) {
    std::vector<char> result;
    for (char ch : line) {
        if (ch != ' ') {
            result.push_back(ch);
        }
    }
    return result;
}

long long qzz1(const std::vector<std::vector<long long>> &data,
               const std::vector<char> &operators) {
    long long total = 0;
    for (size_t i = 0; i < data[0].size(); ++i) {
        long long count = 1;
        if (operators[i] == '*') {
            for (size_t j = 0; j < data.size(); ++j) {
                count *= data[j][i];
            }
            total += count;
        } else if (operators[i] == '+') {
            --count;
            for (size_t j = 0; j < data.size(); ++j) {
                count += data[j][i];
            }
            total += count;
        }
    }
    return total;
}

int main() {
    std::ifstream input("input");
    std::string line;
    std::vector<char> operators;
    std::vector<std::vector<long long>> data;
    while (getline(input, line)) {
        if (!line.empty() && (line[0] != '*' && line[0] != '+')) {
            data.push_back(linetoll(line));
        } else if (!line.empty()) {
            operators = linetochars(line);
        }
    }

    long long qzz1_result = qzz1(data, operators);
    std::cout << "qzz1 result: " << qzz1_result << std::endl;

    input.close();
    return 0;
}
