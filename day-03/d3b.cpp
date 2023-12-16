#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// representation of each symbol's location and char
struct Symbol {
    char symbol;
    int x;
    int y;
};

struct Cell {
    bool isPart;
    int num;
};

// helper function to get the number that any number in the grid is part of
// x and y are the coordinates of that number
int getNumber (vector<vector<Cell>>& grid, int x, int y, int x_max_size) {
    int curr = x;
    int num = 0;

    // find the leftmost digit
    while (curr >= 0 && grid[y][curr].isPart) {
        --curr;
    }
    curr += 1;

    // start adding from left to right
    while (curr < x_max_size && grid[y][curr].isPart) {
        num = (num * 10) + grid[y][curr].num;

        ++curr;
    }

    return num;
}

int main () {
    // setup variables for file reading
    fstream input("input.txt");
    string line;
    int sum = 0;

    // store the grid and symbols
    vector<Symbol> symbols;
    vector<vector<Cell>> grid;

    int yaxis = 0; // easy tracking of y axis

    // read from input file
    while (getline(input, line)) {
        vector<Cell> row;

        // iterate through the characters in the line
        for (int i = 0; i < line.length(); ++i) {
             if (line[i] == '.') { // skip .
                Cell cell;
                cell.isPart = false;
                cell.num = 0;
                row.emplace_back(cell);

            }  else if (isdigit(line[i])) { // number case
                Cell cell;
                cell.isPart = true;
                cell.num = line[i] - '0'; // store the number

                row.emplace_back(cell);
                
            } else { // symbol case
                Symbol sym;
                sym.symbol = line[i];
                sym.y = yaxis;
                sym.x = i;
                symbols.emplace_back(sym);

                Cell cell;
                cell.isPart = false;
                cell.num = 0;
                row.emplace_back(cell);
            }
        }
        
        grid.emplace_back(row);
        ++yaxis;
        
    }

    // for easier reference
    int grid_size_y = grid.size();
    int grid_size_x = grid.back().size();

    // search around each symbol
    for (int i = 0; i < symbols.size(); ++i) {
        if (symbols[i].symbol == '*') {
            // current coordinates, for easier reference
            int x = symbols[i].x;
            int y = symbols[i].y;

            vector<int> gear;
            // NW
            if (x > 0 && y > 0 && grid[y - 1][x - 1].isPart) {
                gear.emplace_back(getNumber(grid, x - 1, y - 1, grid_size_x));
            }

            // N
            if (y > 0 && grid[y - 1][x].isPart && !grid[y - 1][x - 1].isPart) {
                gear.emplace_back(getNumber(grid, x, y - 1, grid_size_x));
            }

            // NE
            if (x + 1 < grid_size_x && y > 0 && grid[y - 1][x + 1].isPart && !grid[y - 1][x].isPart) {
                gear.emplace_back(getNumber(grid, x + 1, y - 1, grid_size_x));
            }

            // W
            if (x > 0 && grid[y][x - 1].isPart) {
                gear.emplace_back(getNumber(grid, x - 1, y, grid_size_x));
            }

            // E
            if (x + 1 < grid_size_x && grid[y][x + 1].isPart) {
                gear.emplace_back(getNumber(grid, x + 1, y, grid_size_x));
            }

            // SW
            if (x > 0 && y + 1 < grid_size_y && grid[y + 1][x - 1].isPart) {
                gear.emplace_back(getNumber(grid, x - 1, y + 1, grid_size_x));
            }

            // S
            if (y + 1 < grid_size_y && grid[y + 1][x].isPart && !grid[y + 1][x - 1].isPart) {
                gear.emplace_back(getNumber(grid, x, y + 1, grid_size_x));
            }

            // SE
            if (x + 1 < grid_size_x && y + 1 < grid_size_y && grid[y + 1][x + 1].isPart && !grid[y + 1][x].isPart) {
                gear.emplace_back(getNumber(grid, x + 1, y + 1, grid_size_x));
            }

            if (gear.size() == 2) {
                sum += (gear.front() * gear.back());
            }

        }

    }


    std::cout << sum << endl;

}
