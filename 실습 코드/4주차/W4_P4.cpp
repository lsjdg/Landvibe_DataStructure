#include <iostream>
using namespace std;

class Node {
public:
    int value = 0;
    Node* next = nullptr;
};

class Queue {
public:
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
        delete delNode;
        size--;
    }
};

int main() {
    int N, T;
    cin >> N;

    while (N--) {
        Queue deckOne = Queue();
        Queue deckTwo = Queue();
        cin >> T;

        for (int i{ 0 }; i < T; i++) {
            int n;
            cin >> n;
            deckOne.enqueue(n);
        }

        for (int i{ 0 }; i < T; i++) {
            int n;
            cin >> n;
            deckTwo.enqueue(n);
        }

        int round{ 1 };
        int scoreOne{ 0 }, scoreTwo{ 0 }, hOne, hTwo;
        int diff{ 0 };
        int winOne{ 0 }, winTwo{ 0 };

        while (T--) {
            cout << "Round" << round++ << ' ';
            hOne = (winOne == 0 ? deckOne.front() + diff : deckOne.front());
            hTwo = (winTwo == 0 ? deckTwo.front() + diff : deckTwo.front());

            deckOne.dequeue();
            deckTwo.dequeue();

            if (hOne > hTwo) {
                cout << hOne << '>' << hTwo << ' ';
                scoreOne++;
                winOne = 1;
                winTwo = 0;
                diff = hOne - hTwo;
            }
            else if (hOne < hTwo) {
                cout << hOne << '<' << hTwo << ' ';
                scoreTwo++;
                winOne = 0;
                winTwo = 1;
                diff = hTwo - hOne;
            }
            else if (hOne == hTwo) {
                cout << hOne << '=' << hTwo << ' ';
                winOne = 0;
                winTwo = 0;
                diff = 0;
            }
            cout << scoreOne << ':' << scoreTwo << '\n';
        }

        if (scoreOne > scoreTwo)
            cout << "Winner P1\n";
        else if (scoreOne < scoreTwo)
            cout << "Winner P2\n";
        else if (scoreOne == scoreTwo) {
            if (winOne == 1)
                cout << "Winner P1\n";
            else if (winTwo == 1)
                cout << "Winner P2\n";
            else if (diff == 0)
                cout << "Draw\n";
        }
    }
}