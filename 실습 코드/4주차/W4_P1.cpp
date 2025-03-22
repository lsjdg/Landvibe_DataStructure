#include <iostream>
using namespace std;

class Node {
public:
    int value = 0;
    Node* next = nullptr;
};

class Queue {
public:
    // enqueue 연산을 O(1)time 에 수행하기 위해 head 에만 dummy node 사용
    Node* head = new Node();
    Node* tail = head;
    int size = 0;


    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }

    int front() {
        if (empty())
            return -1;
        else
            return head->next->value;
    }

    int rear() {
        if (empty()){
            return -1;
        }
        else
            return tail->value;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->value = x;
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void dequeue() {
        if (empty()){
            cout << "Empty\n";
            return;
        }
        Node* delNode = head->next;
        head->next = delNode->next;
        cout << delNode->value << '\n';
        delete delNode;
        size--;

        if (size == 0){
            tail = head;
        }
    }

    void frontNsum(int x) {
        if (empty()){
            cout <<"Empty\n";
            return;
        }
        else if (x > size){
            cout <<"error\n";
            return;
        }
        int sum = 0;
        Node* curNode = head->next;
        while (x--){
            sum += curNode->value;
            curNode = curNode->next;
        }
        cout << sum << '\n';
    }
};

int main() {
    int t;
    cin >> t;

    Queue q = Queue();

    while (t--) {
        string str;
        cin >> str;

        if (str == "size")
            cout << q.getSize() << '\n';
        else if (str == "isEmpty") {
            if (q.empty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (str == "frontNsum") {
            int x;
            cin >> x;

            q.frontNsum(x);
        }
        else if (str == "rear") {
            if (q.empty())
                cout << "Empty\n";
            else
                cout << q.rear() << '\n';
        }
        else if (str == "enqueue") {
            int x;
            cin >> x;

            q.enqueue(x);
        }
        else if (str == "dequeue") {
            q.dequeue();
        }
    }
}