#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("input");

    int count = 0;
    int current = 50;
    char in;
    int next, innum;
    std::string line;
    while (getline(input, line)) {
        in = line[0];
        innum = stoi(line.substr(1));
        count += innum / 100;
        innum %= 100;
        if (in == 'L') {
            innum = -innum;
        }
        next = current + innum;
        if (next > 99) {
            next -= 100;
            count++;
        } else if (next == 0) {
            count++;
        } else if (next < 0 && current != 0) {
            count++;
            next += 100;
        }
        current = (next + 100) % 100;
    }

    std::cout << "Password: " << count << std::endl;
    input.close();
    return 0;
}
