#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>
using namespace std;

struct Node {
    string element;
    string left;
    string right;
};

void findAllStartPos(vector<Node>& nodes, vector<int>& curr) {
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i].element.substr(2, 1) == "A") {
            curr.emplace_back(i);
        }
    }
}

int search(vector<Node>& nodes, string next) { // find index of next node in the vector
    int counter = 0;

    for (auto i : nodes) {
        if (i.element == next) {
            return counter;
        }
        ++counter;
    }

    return 0; // should never reach this line
}

// go through all the instructions
bool traverseInstructions(vector<Node>& nodes, long long int& stepcount, int& node_index, string instructions) {
    for (auto i : instructions) {
        if (nodes[node_index].element.substr(2, 1) == "Z") {
            return true;
        }

        if (i == 'L') { // lhs
            node_index = search(nodes, nodes[node_index].left);
        } else if (i = 'R') { // rhs
            node_index = search(nodes, nodes[node_index].right);
        }
        
        ++stepcount;
    }


    return false;
}

int main() {
    // file reading
    fstream input("input.txt");
    string s;
    
    vector<Node> nodes;
    vector<int> curr;

    string instructions; 
    getline(input, instructions);
    getline(input, s); // skip the newline

    // read in the rest of the puzzle input
    while (getline(input, s)) {
        Node node;

        node.element = s.substr(0, 3);
        node.left = s.substr(7, 3);
        node.right = s.substr(12, 3);

        nodes.emplace_back(node);
    }

    // find all of the nodes that end with A
    findAllStartPos(nodes, curr);
    vector<long long int> stepcounts;

    // determine the number of times it takes for each startpos to get to Z
    for (auto i : curr) {
        bool found = false;
        long long int stepcount = 0;

        while (!found) {
            found = traverseInstructions(nodes, stepcount, i, instructions);
        }

        stepcounts.emplace_back(stepcount);
    }

    // calculate lcm 
    for (int i = 0; i < stepcounts.size() - 1; ++i) {
        stepcounts[i + 1] = lcm(stepcounts[i], stepcounts[i + 1]);
    }

    cout << stepcounts.back() << endl; // final result
}