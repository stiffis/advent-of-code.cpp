#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
long long qzz2(std::vector<std::string> grid) {
    long long count_gen = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool there_changes = true;
    while (there_changes) {
        there_changes = false;
        std::vector<std::pair<int, int>> to_delete;
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
                    to_delete.push_back({i, j});
                }
            }
        }
        if (!to_delete.empty()) {
            count_gen += to_delete.size();
            there_changes = true;
            for (auto p : to_delete) {
                grid[p.first][p.second] = 'X';
            }
        }
    }

    return count_gen;
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

    /*
    std::vector<std::string> grid = {
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

    std::cout << "Count: " << qzz2(grid) << std::endl;

    input.close();
    return 0;
}
