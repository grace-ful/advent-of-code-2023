#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string element;
    string left;
    string right;
};

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
bool traverseInstructions(vector<Node>& nodes, int& stepcount, int& node_index, string instructions) {
    for (auto i : instructions) {
        if (nodes[node_index].element == "ZZZ") {
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
    // read input file
    fstream input("input.txt");
    string s;

    string instructions;
    vector<Node> nodes;

    // read the first line
    getline(input, instructions);
    getline(input, s); // skip the newline

    // read in all the nodes
    while (getline(input, s)) {
        Node node;

        node.element = s.substr(0, 3);
        node.left = s.substr(7, 3);
        node.right = s.substr(12, 3);

        nodes.emplace_back(node);
    }

    bool found = false;
    int stepcount = 0;
    int node_index = search(nodes, "AAA");

    // traverse the instructions
    while (!found) {
        found = traverseInstructions(nodes, stepcount, node_index, instructions);
    }

    cout << stepcount << endl;

}
