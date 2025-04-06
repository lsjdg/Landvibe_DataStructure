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

        if (parentNode == nullptr || find(chi) != nullptr) {
            cout << -1 << '\n';
            return;
        }

        Node* newNode = new Node(parentNode, chi, parentNode->depth + 1);
        parentNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void remove(int x) {
        Node* delNode = find(x);

        if (delNode == nullptr) {
            cout << -1 << '\n';
            return;
        }

        for (auto n : delNode->childList) {
            n->parent = delNode->parent;
            delNode->parent->childList.push_back(n);
        }

        for (int i = 0; i < delNode->parent->childList.size(); i++) {
            if (delNode->parent->childList[i] == delNode) {
                delNode->parent->childList.erase(delNode->parent->childList.begin() + i);
                break;
            }
        }

        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i]->value == x) {
                nodeList.erase(nodeList.begin() + i);
                break;
            }
        }
    }

    void parent(int x) {
        Node* targetNode = find(x);

        if (targetNode == nullptr) {
            cout << -1 << '\n';
            return;
        }

        cout << targetNode->parent->value << '\n';
    }

    void child(int x) {
        Node* targetNode = find(x);

        if (targetNode == nullptr || targetNode->childList.size() == 0) {
            cout << -1 << '\n';
            return;
        }

        for (auto n : targetNode->childList)
            cout << n->value << ' ';

        cout << '\n';
    }

    void minMax(int x) {
        Node* targetNode = find(x);

        if (targetNode == nullptr || targetNode->childList.size() == 0) {
            cout << -1 << '\n';
            return;
        }
        else if (targetNode->childList.size() == 1) {
            cout << targetNode->childList[0]->value << '\n';
            return;
        }

        int min = 10001, max = 0;

        for (auto n : targetNode->childList) {
            if (n->value < min)
                min = n->value;
            if (n->value > max)
                max = n->value;
        }

        cout << min + max << '\n';
    }
};

int main() {
    int test;
    cin >> test;

    Tree t = Tree();

    while (test--) {
        string str;
        cin >> str;

        if (str == "insert") {
            int x, y;
            cin >> x >> y;

            t.insert(x, y);
        }
        else if (str == "remove") {
            int x;
            cin >> x;

            t.remove(x);
        }
        else if (str == "parent") {
            int x;
            cin >> x;

            t.parent(x);
        }
        else if (str == "child") {
            int x;
            cin >> x;

            t.child(x);
        }
        else if (str == "min_maxChild") {
            int x;
            cin >> x;

            t.minMax(x);
        }
    }
}