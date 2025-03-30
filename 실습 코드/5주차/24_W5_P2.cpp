#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    string data;

    Node() {
        next = nullptr;
        prev = nullptr;
        data = " ";
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    Node* iterator;
    int size;

    DoublyLinkedList() {
        head = new Node();
        tail = new Node();
        iterator = nullptr;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void setIterator(int x) {
        iterator = head->next;

        for (int i{ 0 }; i < x; i++)
            iterator = iterator->next;
    }

    void append(string data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (size == 0) { 
            head->next = newNode;
            newNode->prev = head;
            newNode->next = tail;
            tail->prev = newNode;
        } 
        else {
            newNode->next = iterator->next;
            newNode->prev = iterator;
            iterator->next->prev = newNode;
            iterator->next = newNode;
        }

        iterator = newNode;
        size++;
    }

    void cut() {
        if (size == 0) 
            return;

        Node* delNode = iterator;

        if (iterator == tail->prev)
            iterator = iterator->prev;
        else 
            iterator = iterator->next;

        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
        size--;
    }

    void up(int x) {
        if (size == 0)
            return;

        for (int i{ 0 }; i < x; i++) {
            if (iterator->prev != head)
                iterator = iterator->prev;
        }
    }

    void down(int x) {
        if (size == 0)
            return;
            
        for (int i{ 0 }; i < x; i++) {
            if (iterator->next != tail)
                iterator = iterator->next;
        }
    }

    void print() {
        if (size == 0) {
            cout << "And Then There Were None\n";
            return;
        }

        Node* curNode = head->next;

        while (curNode != tail) {
            cout << curNode->data << ' ';
            curNode = curNode->next;
        }
        cout << '\n';
    }
};

int main() {
    int test;
    cin >> test;

    while (test--) {
        int size, cmd, init;
        cin >> size >> cmd >> init;

        DoublyLinkedList table = DoublyLinkedList();

        while (size--) {
            string data;
            cin >> data;

            table.append(data);
        }

        table.setIterator(init);

        while (cmd--) {
            string str;
            cin >> str;

            if (str == "up") {
                int x;
                cin >> x;

                table.up(x);
            }
            else if (str == "down") {
                int x;
                cin >> x;

                table.down(x);
            }
            else if (str == "cut") {
                table.cut();
            }
            else if (str == "append") {
                string name;
                cin >> name;

                table.append(name);
            }
        }

        table.print();
    }
}