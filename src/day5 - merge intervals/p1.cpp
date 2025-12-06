#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct range {
    long long min;
    long long max;
};

long long qzz2(std::vector<range> ranges) {
    std::sort(ranges.begin(), ranges.end(),
              [](const range &a, const range &b) { return a.min < b.min; });
    long long total = 0;
    std::vector<std::pair<long long, long long>> merged;
    for (const auto &r : ranges) {
        if (merged.empty() || merged.back().second < r.min) {
            merged.push_back({r.min, r.max});
        } else {
            merged.back().second = std::max(merged.back().second, r.max);
        }
    }
    for (const auto &r : merged) {
        total += r.second - r.first + 1;
    }
    return total;
}

long long qzz1(const std::vector<range> &ranges,
               const std::vector<long long> &data) {
    long long count = 0;
    for (const auto &num : data) {
        for (const auto &r : ranges) {
            if (num >= r.min && num <= r.max) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    std::ifstream input("input");

    std::string line;
    std::vector<range> ranges;
    std::vector<long long> data;

    bool leyendo_primera_parte = true;

    while (std::getline(input, line)) {
        if (line.empty()) {
            leyendo_primera_parte = false;
            continue;
        }

        if (leyendo_primera_parte) {
            std::stringstream ss(line);
            long long n1, n2;
            char guion;

            if (ss >> n1 >> guion >> n2) {
                ranges.push_back({n1, n2});
            }

        } else {
            data.push_back(std::stoll(line));
        }
    }

    long long result = qzz1(ranges, data);
    long long total = qzz2(ranges);
    std::cout << "General count: " << result << std::endl;
    std::cout << "Total numbers in ranges without overlap: " << total
              << std::endl;
    input.close();
    return 0;
}
