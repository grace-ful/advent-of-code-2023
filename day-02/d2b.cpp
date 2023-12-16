#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const string GAME = "Game";
const string RED = "red";
const string BLUE = "blue";
const string GREEN = "green";

struct Game {
    int red;
    int green;
    int blue;
};

int main () {
    // setup file reading
    fstream input("input.txt");
    string s;

    int sum = 0;

    // read the input
    while (getline(input, s)) {
        // read word by word
        istringstream line(s);
        string word;

        Game current = Game{0}; // current game

        while (line >> word) {
            if (word == GAME) { // skip past the Game N: section
                line >> word;
                continue;
            }

            int colnum = stoi(word); // store the number
            line >> word;

            if (word.find(RED) != string::npos) {
                current.red = max(colnum, current.red);
            }

            if (word.find(BLUE) != string::npos) {
                current.blue = max(colnum, current.blue);
            }

            if (word.find(GREEN) != string::npos) {
                current.green = max (colnum, current.green);
            }
        }

        // determine the power
        int power = current.red * current.blue * current.green;
        sum += power;

    }

    cout << sum << endl;

}
