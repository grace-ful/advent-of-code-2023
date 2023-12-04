#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>
using namespace std;

const string CARD = "Card";
const int CARDTOTAL = 186; // given in the question

int main() {
    // setup variables for file reading
    fstream input("input.txt");
    string s;

    vector<int> cardcount(CARDTOTAL, 1);
    int count = 1;

    int sum = 0;

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

        for (int i = 0; i < cardcount[count - 1]; ++i) { // every copy of the card
            for (int j = 0; j < matches; ++j) {
                ++cardcount[count + j];
            }
        }

        ++count;
    }

    for (int i = 0; i < cardcount.size(); ++i) {
        sum += cardcount[i];
    }

    cout << sum << endl;

}
