//
// Created by 이승준 on 3/17/25.
//
#include <iostream>
using namespace std;

int t;

class Node {
public:
    int value;
    Node* next;

    Node() {
        this->value = 0;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;


    SinglyLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        size = 0;
    }

    // head 뒤에 삽입
    void Append(int x) {
        Node* newNode = new Node();
        newNode->value = x;
        newNode->next = this->head->next;
        this->head->next = newNode;
        this->size++;
    }

    void Delete() {
        Node* delNode = this->head->next;
        this->head->next = delNode->next;
        delete delNode;
        this->size--;
    }
};

class Stack{
public:
    SinglyLinkedList ll;

    Stack() {
        this->ll = SinglyLinkedList();
    }

    int getSize(){
        return ll.size;
    }

    bool isEmpty(){
        return (ll.size == 0);
    }

    int top(){
        if (isEmpty()){
            return -1;
        }
        return ll.head->next->value;
    }

    void push(int x){
        if (ll.size >= t){
            cout << "FULL\n";
            return;
        }
        ll.Append(x);
    }

    void pop(){
        if (isEmpty()){
            return;
        }
        ll.Delete();
    }
};

int main() {
    int N;
    cin >> t >> N;
    Stack st = Stack();

    while (N--) {
        string str;
        cin >> str;

        if (str == "size")
            cout << st.getSize() << '\n';
        else if (str == "empty") {
            if (st.isEmpty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (str == "top") {
            cout << st.top() << '\n';
        } else if (str == "push") {
            int x;
            cin >> x;

            st.push(x);
        }
    }
}