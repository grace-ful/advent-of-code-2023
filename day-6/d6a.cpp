#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

struct Race {
    int time;
    int distance;
};

void setupTimes (string& s, vector<Race>& races) {
    istringstream line(s);
    string word;

    line >> word; // skip Time:

    while (line >> word) {  
        Race race;
        race.time = stoi(word);

        races.emplace_back(race);
    }
}

void setupDistance (string& s, vector<Race>& races) {
    istringstream line(s);
    string word;

    line >> word; // skip Distance:
    int counter = 0;

    while (line >> word) {
        races[counter].distance = stoi(word);

        ++counter;
    }
}

int determineWins (int time, int distance) {
    int n = 1;

    while ((time - n) * n <= distance) {
        ++n;
    }

    return n;
}

int main () {
    // setup variables for file reading
    fstream input("input.txt");
    string s;

    vector<Race> races;

    int product = 1;

    // read time
    getline(input, s);
    setupTimes(s, races);

    // read distance
    getline(input, s);
    setupDistance(s, races);

    // perform calculations for number of winning combinations
    for (auto i : races) {
        int n = determineWins(i.time, i.distance);

        n = (i.time - n) - n + 1;

        product *= n;
    }

    cout << product << endl; // assuming none of n are 0

}
