#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {

    // setup variables
    fstream input("input.txt");
    string line;
    int output = 0;

    // read from input file
    while (getline(input, line)) {
        bool seenFirst = false;
        string first;
        string last;
        int total = 0;

        // get the first and last digit of each line
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] >= 48 && line[i] <= 57) {
                if (seenFirst) {
                    last = line[i];
                } else {
                    first = line[i];
                    last = line[i];
                    seenFirst = true;
                }
            }
        }

        first.append(last);
        total = stoi(first);

        output += total;
    }

    cout << output << endl;

}
