#include <iostream>
using namespace std;

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

	void Print() {
		if (size == 0) 
			cout << "empty" << '\n';
		else {
			Node* curNode = head->next;

			for (int i{ 0 }; i < size; i++) {
			cout << curNode->value << ' ';
			curNode = curNode->next;
			}
			cout << '\n';
		}
	}

	void Append(int x) {
		Node* newNode = new Node();
		newNode->value = x;
		Node* curNode = head;
		for (int i{ 0 }; i < size; i++) {
			curNode = curNode->next;
		}
		newNode->next = tail;
		curNode->next = newNode;
		size++;
	}
	
	void InsertBefore(int e, int v) {
        Node* newNode = new Node();
        newNode->value = v;
        
        
        Node* curNode = head;
        while (curNode->next != nullptr && curNode->next->value != e) 
            curNode = curNode->next;
        
        if (curNode->next != nullptr) {
            newNode->next = curNode->next;
            curNode->next = newNode;
            size++;
        }
    }

    SinglyLinkedList Merge(SinglyLinkedList& other) {
        Node* curNode = other.head->next; 
        while (curNode != other.tail) { 
            this->Append(curNode->value); 
            curNode = curNode->next; 
        }
        return *this; 
    }
};

int main() {
	int test;
	cin >> test;

	while (test--) {
        SinglyLinkedList L1, L2, Lmerge;
        
        int n1;
        cin >> n1;

        for (int i{ 0 }; i < n1; i++) {
            int x1;
            cin >> x1;

            L1.Append(x1);
        }

        int n2;
        cin >> n2;

        for (int i{ 0 }; i < n2; i++) {
            int x2;
            cin >> x2;

            L2.Append(x2);
        }

        Lmerge = L1.Merge(L2);
        Lmerge.Print();
        
        int e, v;
        cin >> e >> v;
        
        Lmerge.InsertBefore(e, v);
        Lmerge.Print();
    }
}