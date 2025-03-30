//
// Created by 이승준 on 3/30/25.
//
#include <iostream>
using namespace std;

class Node{
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    char value;
};

class Iterator{
public:
    Node* node;
    Iterator(){
        node = nullptr;
    }
    void set(Node* node) {
        this->node = node;
    }

    Node *get() {
        return node;
    }

    // ++iter 오버로딩
    Iterator *operator++() {
        node = node->next;
        return this;
    }

    // --iter 오버로딩
    Iterator *operator--() {
        node = node->prev;
        return this;
    }
};

class Sequence{
public:
    Node* head;
    Node* tail;
    int size;

    Sequence(){
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    Node* begin(){
        return head->next;
    }
    Node* end(){
        return tail;
    }
    void insert(Iterator& p, char e){
        Node* newNode = new Node();
        newNode->value = e;

        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;
        newNode->next = p.node;
        p.node->prev = newNode;
        this->size++;
    }
    void erase(Iterator& p){
        if (size == 0 | p.node == head->next)
            return;
        Node* deleteNode = p.node->prev;
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        size--;
        delete deleteNode;
    }
    void next(Iterator& p){
        if (p.node == tail)
            return;
        ++p;
    }
    void prev(Iterator& p){
        if (p.node == head->next)
            return;
        --p;
    }
    void print(){
        if (size == 0)
            cout << "Empty\n";
        else{
            Node* curNode = head->next;
            while (curNode != tail){
                cout << curNode->value;
                curNode = curNode->next;
            }
            cout << '\n';
        }
    }
};

int main(){
    Sequence sq = Sequence();
    string str;
    Iterator p = Iterator();
    p.set(sq.begin());
    cin >> str;

    for (size_t i = 0; i < str.size(); i++){
        sq.insert(p, str[i]);
    }
    int test;
    cin >> test;
    while (test--){
        string command;
        cin >> command;
        if (command == "L"){
            sq.prev(p);
        }
        else if (command == "D"){
            sq.next(p);
        }
        else if (command == "B"){

            sq.erase(p);
        }
        else if (command == "P"){
            char c;
            cin >> c;
            sq.insert(p, c);
        }
    }
    sq.print();
}