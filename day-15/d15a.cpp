#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // file setup
    fstream input("input.txt");
    string s;

    int sum = 0;

    while (getline(input, s, ',')) {
        int curr = 0;

        for (auto i : s) {
            curr += i;
            curr *= 17;
            curr = curr % 256;
        }

        sum += curr;
    }

    cout << sum << endl;
}
