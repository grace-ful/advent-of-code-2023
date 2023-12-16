#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std; 

int hashLabel(string& s) {
    int curr = 0;

    for (auto i : s) {
        curr += i;
        curr *= 17;
        curr = curr % 256;
    }

    return curr;
}

void prettyprint(vector<vector<pair<string, int>>>& hashmap) {
    int counter = 0;
    for (auto i : hashmap) {
        if (!i.empty()) {
            cout << "Box " << counter << ":";
        
        for (auto j : i) {
            cout << " [";  
            cout << j.first << " " << j.second;
            cout << "]";
        }

            cout << endl;
        }
        ++counter;
    }
}

bool search(vector<pair<string, int>>& box, string key) {
    for (auto i : box) {
        if (i.first == key) {
            return true;
        }
    }

    return false;
}

void remove(vector<pair<string, int>>& box, string key) {
    int counter = 0;
    for (auto i : box) {
        if (i.first == key) {
            break;
        }
        ++counter;
    }

    box.erase(box.begin()+counter);
}

void replace(vector<pair<string, int>>&box, string key, int value) {
    for (int i = 0; i < box.size(); ++i) {
        if (box[i].first == key) {
            box[i].second = value;
        }
    }
}

void insert(vector<pair<string, int>>& box, string key, int value) {
    box.emplace_back(make_pair(key, value));
}

int boxSum(vector<pair<string, int>>& box, int boxnum) {
    int sum = 0;

    for (int i = 0; i < box.size(); ++i) {
       sum += (boxnum + 1) * (i + 1) * box[i].second;
    }

    return sum;
}

int main() {
    // read file
    fstream input("input.txt");
    string s;

    vector<vector<pair<string, int>>> hashmap(256);

    while (getline(input, s, ',')) {
        // find operation
        size_t foundDash = s.find('-');
        if (foundDash != string::npos) { // dash case - remove from hashmap
            // HASH the label
            string key = s.substr(0, foundDash);
            int box = hashLabel(key);

            // does the key exist
            bool keyExist = search(hashmap[box], key);

            // search the hash map
            if (keyExist) { // if key exists, remove
                remove(hashmap[box], key);
            }
        } else { // equals case - insert into the hashmap
            size_t foundEquals = s.find('=');
            
            // HASH the label
            string key = s.substr(0, foundEquals);
            int box = hashLabel(key);

            // does the key exist
            bool keyExist = search(hashmap[box], key);

            int value = stoi(s.substr(foundEquals + 1, 1));
            if (keyExist) {
                replace(hashmap[box], key, value);
            } else {
                insert(hashmap[box], key, value);
            }

        }
    }

    int sum = 0;

    // add up the focusing power
    int boxnum = 0;
    for (auto i : hashmap) { // for each row of the hashmap
        if (!i.empty()) {
            sum += boxSum(i, boxnum);
        }
        ++boxnum;
    }

    cout << sum << endl;

}
