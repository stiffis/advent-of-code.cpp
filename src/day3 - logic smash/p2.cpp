#include <fstream>
#include <iostream>
#include <string>
const int NUM_DIGIT_TAKE = 12;

long long pzzl2(const std::string &line) {
    if (line.size() < NUM_DIGIT_TAKE)
        return 0;
    std::string result;
    int last_pos = -1;
    for (int k = 0; k < NUM_DIGIT_TAKE; k++) {
        char max_val = -1;
        int max_idx = -1;
        int digits_needed_after = NUM_DIGIT_TAKE - 1 - k;
        int search_limit = line.size() - digits_needed_after;
        for (int i = last_pos + 1; i < search_limit; i++) {
            if (line[i] > max_val) {
                max_val = line[i];
                max_idx = i;
                if (max_val == '9')
                    break;
            }
        }
        result += max_val;
        last_pos = max_idx;
    }
    return std::stoll(result);
}

int main() {
    std::ifstream input("input");

    std::string line;
    long long sum = 0;
    while (std::getline(input, line)) {
        sum += pzzl2(line);
    }

    std::cout << "General sum: " << sum << std::endl;
    input.close();
    return 0;
}
