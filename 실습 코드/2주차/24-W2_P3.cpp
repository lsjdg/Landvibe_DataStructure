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
		Print();
	}
	
	void Delete(int idx) {
		if (size == 0 || idx >= size) 
			cout << -1 << '\n';
		else {
			Node* curNode = head;

			for (int i{ 0 }; i < idx; i++) {
				curNode = curNode->next;
			}

			Node* delNode = curNode->next;
			curNode->next = delNode->next;
			cout << delNode->value << '\n';
			delete delNode;
			size--;
		}
	}

	void AfterMin(int idx) {
		if (size == 0 || idx >= size) 
			cout << "error" << '\n';
		else {
			Node* curNode = head->next;

			for (int i{ 0 }; i < idx; i++) 
				curNode = curNode->next;

			int min = curNode->value;

			while (curNode->next != nullptr) {
				if (curNode->value < min) 
					min = curNode->value;
				curNode = curNode->next;
			}

			cout << min << '\n';
		}
	}

	void Sum() {
		if (size == 0) 
			cout << 0 << '\n';
		else {
			int sum{ 0 };
			Node* curNode = head->next;

			for (int i{ 0 }; i < size; i++) {
				sum += curNode->value;
				curNode = curNode->next;
			}
			
			cout << sum << '\n';
		}
	}
};

int main() {
	int test;
	cin >> test;

	SinglyLinkedList l = SinglyLinkedList();

	while(test--) {
		string str;
		cin >> str;

		if (str == "Print") {
			l.Print();
		}
		else if (str == "Append") {
			int x;
			cin >> x;

			l.Append(x);
		}
		else if (str == "Delete") {
			int idx;
			cin >> idx;

			l.Delete(idx);
		}
		else if (str == "AfterMin") {
			int idx;
			cin >> idx;

			l.AfterMin(idx);
		}
		else if (str == "Sum") {
			l.Sum();
		}
	}
}