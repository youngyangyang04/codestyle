#include<iostream>
#include<map>
using namespace std;

struct Node {
    int a;
    float b;
    string c;
}st;

int main (){

    // map<int, Node> node_map;
    // Node node;
    // node.a = 1;
    // node.b = 1.1;
    // node.c = "adf";
    // node_map[0] = node;

    // Node node1;
    // node1.a = 2;
    // node1.b = 1.1;
    // node1.c = "2adf";
    // node_map[1] = node1;

    // Node node2;
    // node2.a = 3;
    // node2.b = 3.1;
    // node2.c = "3adf";
    // node_map[2] = node2;

    // Node node3;
    // node3.a = 3;
    // node3.b = 3.1;
    // node3.c = "3adf";
    // node_map[3] = node3;

    map<int, Node> node_map = {
        {0,{1, 1.1, "adf"}},
        {1,{2, 1.1, "1adf"}},
        {2,{3, 1.1, "2adf"}},
        {3,{3, 1.1, "3adf"}},
    };

    for (pair<int, Node> node_pair : node_map) {
        cout << node_pair.second.c << endl;
    }

}

