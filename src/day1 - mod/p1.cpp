#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("input");

    int count = 0;
    int current = 50;
    char in;
    int innum;
    std::string line;
    while (getline(input, line)) {
        in = line[0];
        innum = stoi(line.substr(1));
        if (in == 'R') {
            current += innum;
        } else {
            current -= innum;
        }
        current = (current % 100 + 100) % 100;
        if (current == 0) {
            count++;
        }
    }

    std::cout << "Password: " << count << std::endl;
    input.close();
    return 0;
}
