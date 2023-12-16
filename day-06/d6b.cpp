#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void setupTime (string& time, string& s) {
    istringstream line(s);
    string word;

    line >> word; // skip Time:

    while (line >> word) {
        time.append(word);
    }
}

void setupDistance (string& distance, string& s) {
    istringstream line(s);
    string word;

    line >> word; // skip Distance:

    while (line >> word) {
        distance.append(word);
    }
}

int determineWins (long long int time, long long int distance) {
    int n = 1;

    while ((time - n) * n <= distance) {
        ++n;
    }

    return n;
}

int main () {
    // file reading
    // setup variables for file reading
    fstream input("input.txt");
    string s;

    string time = "";
    string distance = "";

    // read input
    getline(input, s);
    setupTime(time, s);

    getline(input, s);
    setupDistance(distance, s);

    // perform calculation for winning combination
    long long int winning = determineWins(stoll(time), stoll(distance));

    winning = (stoll(time) - winning) - winning + 1;

    cout << winning << endl;

}
