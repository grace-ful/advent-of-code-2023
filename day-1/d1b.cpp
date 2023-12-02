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

        int i = 0;
        int length = line.length();

        // iterate through all the characters in the line to find first and last
        while (i < length) {
            if (line[i] >= 48 && line[i] <= 57) { // 0-9
                if (seenFirst) {
                    last = line[i];
                } else {
                    first = line[i];
                    last = line[i];
                    seenFirst = true;
                }

                ++i;
            } else { // a-z
                switch (line[i]) {
                case 111: // o
                    if (i + 2 < length && line[i + 1] == 'n' && line[i + 2] == 'e') { // one
                        if (seenFirst) {
                            last = '1';
                        } else {
                            first = '1';
                            last = '1';
                            seenFirst = true;
                        }
                        i += 2; // share the e with eight
                    } else {
                        ++i;
                    }
                    break;
                case 116: // t
                    if (i + 2 < length && line[i + 1] == 'w' && line[i + 2] == 'o') { // two
                       if (seenFirst) {
                            last = '2';
                        } else {
                            first = '2';
                            last = '2';
                            seenFirst = true;
                        } 
                        i += 2; // share the o with one
                    } else if (i + 4 < length && line[i + 1] == 'h' && line[i + 2] == 'r' &&
                        line[i + 3] == 'e' && line[i + 4] == 'e') { // three
                        if (seenFirst) {
                            last = '3';
                        } else {
                            first = '3';
                            last = '3';
                            seenFirst = true;
                        } 
                        i += 4; // share the e with eight
                    } else {
                        ++i;
                    }
                    break;
                case 102: // f
                    if (i + 3 < length && line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r') { // four
                        if (seenFirst) {
                            last = '4';
                        } else {
                            first = '4';
                            last = '4';
                            seenFirst = true;
                        } 
                        i += 4;
                    } else if (i + 3 < length && line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e') { // five
                        if (seenFirst) {
                            last = '5';
                        } else {
                            first = '5';
                            last = '5';
                            seenFirst = true;
                        } 
                        i += 3; // share the e with eight
                    } else {
                        ++i;
                    }
                    break;
                case 115: // s
                    if (i + 2 < length && line[i + 1] == 'i' && line[i + 2] == 'x') { // six
                        if (seenFirst) {
                            last = '6';
                        } else {
                            first = '6';
                            last = '6';
                            seenFirst = true;
                        } 
                        i += 3;
                    } else if (i + 4 < length && line[i + 1] == 'e' && line[i + 2] == 'v' && 
                        line[i + 3] == 'e' && line[i + 4] == 'n') { // seven
                        if (seenFirst) {
                            last = '7';
                        } else {
                            first = '7';
                            last = '7';
                            seenFirst = true;
                        } 
                        i += 4; // share the n with nine
                    } else {
                        ++i;
                    }
                    break;
                case 101: // e
                    if (i + 4 < length && line[i + 1] == 'i' && line[i + 2] == 'g' && 
                        line[i + 3] == 'h' && line[i + 4] == 't') { // eight
                        if (seenFirst) {
                            last = '8';
                        } else {
                            first = '8';
                            last = '8';
                            seenFirst = true;
                        } 
                        i += 4; // share the t with two, three
                    } else {
                        ++i;
                    }
                    break;
                case 110: // n
                    if (i + 3 < length && line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e') { // nine
                        if (seenFirst) {
                            last = '9';
                        } else {
                            first = '9';
                            last = '9';
                            seenFirst = true;
                        } 
                        i += 3; // share the e with eight
                    } else {
                        ++i;
                    }
                    break;
                default:
                    ++i; // go to next letter
                    break;
                }


            }
        }

        first.append(last);
        total = stoi(first);

        output += total;

    }

    cout << output << endl;

}


