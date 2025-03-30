#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int value;

    Node() {
        next = nullptr;
        prev = nullptr;
        value = 0;
    }
};

class Sequence {
public:
    Node* head;
    Node* tail;
    int size;

    Sequence() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insert(int idx, int value) {
        if (idx < 0 || idx > size) {
            cout << "out_of_range\n";
            return;
        }

        Node* newNode = new Node();
        newNode->value = value;
        Node* curNode = head;

        for (int i = 0; i < idx; i++)
            curNode = curNode->next;

        newNode->next = curNode->next;
        curNode->next->prev = newNode;
        curNode->next = newNode;
        newNode->prev = curNode;
        size++;
    }

    void erase(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "out_of_range\n";
            return;
        }

        Node* delNode = head->next;

        for (int i = 0; i < idx; i++)
            delNode = delNode->next;

        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
        size--;
    }

    void empty() {
        cout << (size == 0 ? "true\n" : "false\n");
    }

    void find(int x) {
        int idx = 0;
        Node* curNode = head->next;

        while (curNode != tail) {
            if (curNode->value == x)
                break;
            curNode = curNode->next;
            idx++;
        }

        if (curNode == tail)
            cout << "not_found\n";
        else
            cout << idx << '\n';
    }

    void print(int m) {
        if (size == 0) {
            cout << "empty\n";
            return;
        }

        if (m == 0) {
            Node* curNode = head->next;
            while (curNode->next != nullptr) {
                cout << curNode->value << ' ';
                curNode = curNode->next;
            }
        }
        else {
            Node* curNode = tail->prev;
            while (curNode->prev != nullptr) {
                cout << curNode->value << ' ';
                curNode = curNode->prev;
            }
        }

        cout << '\n';
    }
};

int main() {
    int test;
    cin >> test;

    Sequence s = Sequence();

    while (test--) {
        string str;
        cin >> str;

        if (str == "insert") {
            int i, x;
            cin >> i >> x;

            s.insert(i, x);
        }
        else if (str == "erase") {
            int i;
            cin >> i;

            s.erase(i);
        }
        else if (str == "empty") {
            s.empty();
        }
        else if (str == "find") {
            int x;
            cin >> x;

            s.find(x);
        }
        else if (str == "print") {
            int m;
            cin >> m;

            s.print(m);
        }
    }
}