#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool isAllZero(vector<int>& row) {
    bool isAllZero = true;
    for (auto i: row) {
        if (i != 0) {
            isAllZero = false;
            break;
        }
    }

    return isAllZero;
}

void findHistory(vector<int>& row) {
    if(isAllZero(row)) { // base case
        row.emplace_back(0);
    } else { // still need to reach all-zero differences
        vector<int> bottom;

        for (int i = 0; i < row.size() - 1; ++i) {
            bottom.emplace_back(row[i+1] - row[i]);
        } // create the bottom row

        findHistory(bottom);

        int next = row.back() + bottom.back();
        row.emplace_back(next);
    }
}

int main () {
    // setup for reading file
    fstream file("input.txt");
    string s;

    vector<vector<int>> oasis;

    int sum = 0;

    // read input file
    while (getline(file, s)) {
        // read each row
        istringstream line(s);
        string word;

        vector<int> row;

        while (line >> word) {
            row.emplace_back(stoi(word));
        }

        oasis.emplace_back(row);
    }

    // calculate for each row
    for (auto i: oasis) {
       findHistory(i);
       sum += i.back();
    }

    cout << sum << endl;

}
