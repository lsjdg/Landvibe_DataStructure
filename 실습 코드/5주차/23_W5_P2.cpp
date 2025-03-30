#include <iostream>
using namespace std;

class Node{
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    int value;
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
        if (size == 0 | p.node == end())
            return;
        Node* deleteNode = p.node;
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        size--;
        delete deleteNode;
        p.set(begin());
    }
    void nextP(Iterator& p){
        if (p.node == tail)
            return;
        ++p;
    }
    void prevP(Iterator& p){
        if (p.node == head->next)
            return;
        --p;
    }
    void findMultiple(int e) {
        int count = 0, idx = 0;
        Iterator q = Iterator();
        q.node = begin();

        while (q.node != end()) {
            if (q.node->value % e == 0) {
                cout << idx << ' ';
                count++;
            }
            idx++;
            nextP(q);
        }

        if (count == 0)
            cout << -1 << '\n';
        else
            cout << '\n';
    }
};

int main() {
    int test;
    cin >> test;

    while (test--) {
        int len;
        cin >> len;
        Sequence sq = Sequence();
        Iterator p = Iterator();
        p.node = sq.head->next;

        while (len--) {
            int e;
            cin >> e;
            sq.insert(p, e);
        }

        p.node = sq.begin();
        int moves;
        cin >> moves;

        while (moves--) {
            int jump;
            cin >> jump;

            if (jump > 0) {
                for (int i = 0; i < jump; i++) {
                    sq.nextP(p);
                    if (p.node == sq.tail)
                        break;
                }
            }
            else {
                jump *= -1;
                for (int i = 0; i < jump; i++) {
                    sq.prevP(p);
                    if (p.node == sq.head->next)
                        break;
                }
            }

            jump = p.node->value;

            if (jump > 0) {
                for (int i = 0; i < jump; i++) {
                    sq.nextP(p);
                    if (p.node == sq.tail)
                        break;
                }
            }
            else {
                jump *= -1;
                for (int i = 0; i < jump; i++) {
                    sq.prevP(p);
                    if (p.node == sq.head->next)
                        break;
                }
            }
        }
        cout << p.node->value << '\n';
    }
}