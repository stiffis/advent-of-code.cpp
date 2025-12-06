#include <fstream>
#include <iostream>
#include <string>
#include <vector>

long long qzz1(const std::vector<std::string> &grid) {
    long long count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    std::vector<std::pair<int, int>> coords;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != '@')
                continue;
            int neighbors = 0;
            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    if (grid[ni][nj] == '@') {
                        neighbors++;
                    }
                }
            }
            if (neighbors < 4) {
                coords.push_back({i, j});
            }
        }
    }
    if (!coords.empty()) {
        count += coords.size();
    }
    return count;
}

int main() {
    std::ifstream input("input");
    std::vector<std::string> grid;
    std::string line;

    while (getline(input, line)) {
        if (!line.empty()) {
            grid.push_back(line);
        }
    }

    /*std::vector<std::string> grid = {
        "..@@.@@@@.", //
        "@@@.@.@.@@", //
        "@@@@@.@.@@", //
        "@.@@@@..@.", //
        "@@.@@@@.@@", //
        ".@@@@@@@.@", //
        ".@.@.@.@@@", //
        "@.@@@.@@@@", //
        ".@@@@@@@@.", //
        "@.@.@@@.@."  //
    };*/

    std::cout << "Count: " << qzz1(grid) << std::endl;
    input.close();
    return 0;
}
