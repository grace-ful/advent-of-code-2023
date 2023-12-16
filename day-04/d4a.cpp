#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>
using namespace std;

const string CARD = "Card";

int main (){
    // setup variables for file reading
    fstream input("input.txt");
    string s;

    int total = 0;

    // parse input
    while (getline(input, s)) {
        // read word by word
        istringstream line(s);
        string word;

        bool seenmid = false;
        vector<int> winning;
        int matches = 0;

        while (line >> word) {
            // skip Card N text
            if (word == CARD) {
                line >> word;
                continue;
            }

            if (!seenmid) {
                if (word[0] == '|') { // seen divider
                    seenmid = true;
                } else { // number case
                    winning.emplace_back(stoi(word));
                }
            } else {
                int mynum = stoi(word);

                vector<int>::iterator it;
                it = find(winning.begin(), winning.end(), mynum);

                if (it != winning.end()) { // found 
                    ++matches;
                }

            }
        }

        // finished reading the line
        if (matches > 0) {
            -- matches;
            total += pow(2, matches);
        }

    }

    cout << total << endl;

}
