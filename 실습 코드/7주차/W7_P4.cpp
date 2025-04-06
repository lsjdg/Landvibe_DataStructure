#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* parent;
    vector<Node*> childList;
    int value;
    int depth;

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

    void parentSum(Node* node) {
        int sum = 0;
        char type;
        type = node->childList.size() != 0 ? 'F' : 'D';
        Node* temp = node->parent;

        while (temp != nullptr) {
            sum += temp->value;
            temp = temp->parent;
        }

        cout << type << " " << sum << '\n';
    }
};

int main() {
    int nodes, test;
    cin >> nodes >> test;

    Tree t = Tree();

    for (int i = 1; i < nodes; i++) {
        int par, chi;
        cin >> par >> chi;

        t.insert(par, chi);
    }

    while (test--) {
        int target;
        cin >> target;
        Node* targetNode = t.find(target);

        t.parentSum(targetNode);
    }
}