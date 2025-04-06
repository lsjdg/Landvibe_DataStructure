#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* parent;
    vector<Node*> childList;
    int value;
    int depth;
    int file;
    int capa;

    Node(Node* parent, int value, int depth) {
        this->parent = parent;
        this->value = value;
        this->depth = depth;
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> nodeList;

    Tree() {
        root = new Node(nullptr, 1, 0);
        nodeList.push_back(root);
    }

    Node* find(int x) {
        for (auto n : nodeList) {
            if (n->value == x)
                return n;
        }
        return nullptr;
    }

    void insert(int par, int chi) {
        Node* parentNode = find(par);

        if (parentNode == nullptr || find(chi) != nullptr)
            return;

        Node* newNode = new Node(parentNode, chi, parentNode->depth + 1);
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    int count(Node* node) {
        int sum = 0;
        for (auto n : node->childList)
            sum += count(n);
        sum += node->file;
        return sum;
    }
};

int main() {
    int nodes, questions;
    cin >> nodes >> questions;

    Tree t = Tree();

    for (int i = 1; i < nodes; i++) {
        int par, chi;
        cin >> par >> chi;
        t.insert(par, chi);
    }

    for (int i = 0; i < nodes; i++) {
        int v, file;
        cin >> v >> file;
        Node* target = t.find(v);
        target->file = file;
    }

    for (auto n : t.nodeList) {
        n->capa = t.count(n);
    }

    for (int i = 0; i < questions; i++) {
        int nodeNum;
        cin >> nodeNum;

        cout << t.find(nodeNum)->capa << '\n';
    }
}