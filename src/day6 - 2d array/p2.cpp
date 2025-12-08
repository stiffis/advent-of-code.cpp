#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// this is so ad-hoc
std::vector<char> linetochars(const std::string &line) {
    std::vector<char> result;
    for (char ch : line) {
        if (ch != ' ') {
            result.push_back(ch);
        }
    }
    return result;
}

bool strfullofspaces(const std::string s) {
    for (char ch : s) {
        if (ch != ' ') {
            return false;
        }
    }
    return true;
}

std::string deletespaces(const std::string s) {
    std::string result = "";
    for (char ch : s) {
        if (ch != ' ') {
            result.push_back(ch);
        }
    }
    return result;
}

std::vector<std::vector<long long>> readdata(std::vector<std::string> &data) {
    std::vector<std::vector<long long>> cleaned;
    std::vector<long long> row;
    for (long i = data[0].size() - 1; i >= 0; --i) {
        std::string temp = "";
        for (size_t j = 0; j < data.size(); ++j) {
            temp.push_back(data[j][i]);
        }
        if (!strfullofspaces(temp)) {
            row.push_back(std::stoll(deletespaces(temp)));
        } else {
            if (!row.empty()) {
                cleaned.push_back(row);
                row.clear();
            }
        }
    }
    if (!row.empty()) {
        cleaned.push_back(row);
        row.clear();
    }
    return cleaned;
}

long long qzz2(const std::vector<std::vector<long long>> data,
               const std::vector<char> operators) {
    long long total = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        long long count = (operators[i] == '*') ? 1 : 0;
        if (operators[i] == '*') {
            for (size_t j = 0; j < data[i].size(); ++j) {
                count *= data[i][j];
            }
            total += count;
        } else if (operators[i] == '+') {
            for (size_t j = 0; j < data[i].size(); ++j) {
                count += data[i][j];
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
    std::vector<std::string> data;

    while (getline(input, line)) {
        if (!line.empty() && (line[0] != '*' && line[0] != '+')) {
            data.push_back(line);
        } else if (!line.empty()) {
            operators = linetochars(line);
        }
    }

    std::vector<std::vector<long long>> cleaned = readdata(data);

    std::reverse(operators.begin(), operators.end());

    long long result = qzz2(cleaned, operators);
    std::cout << "Final result: " << result << std::endl;

    input.close();
    return 0;
}
