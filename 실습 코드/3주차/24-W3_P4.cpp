#include <iostream>
using namespace std;

int maxSize;

class Node {
public:
	char value;
	Node* next;

	Node() {
		this->value = 0;
		this->next = nullptr;
	}
};

class Stack {
public:
	Node* head;
	Node* tail;
	int size;

	Stack() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool empty() {
		return size == 0;
	}

	char top() {
		if (empty())
			return 'c';
		else
			return head->next->value;
	}

	void push(char x) {
		Node* newNode = new Node();
		newNode->value = x;
		newNode->next = head->next;
		head->next = newNode;
		size++;
        if (maxSize < size)
            maxSize = size;
	}

	void pop() {
		if (empty())
			return;
		else {
			Node* delNode = head->next;
			head->next = delNode->next;
			delete delNode;
			size--;
		}
	}
};

bool isOper(char c) {
	if (c == '+' || c == '-' || c == '*')
		return true;
	return false;
}

int main() {
	int test;
	cin >> test;

	while (test--) {
		string str;
		cin >> str;

		Stack s = Stack();
        maxSize = 0;

		for (int i = 0; i < str.size(); i++) {
			char c = str[i];

			if (!isOper(c)) 
				cout << c;
			else {
				if (c == '+' || c == '-') {
					while (!s.empty()) {
						cout << s.top();
						s.pop();
					}
					s.push(c);
				}
				else if (c == '*') {
					while (s.top() == '*') {
						cout << s.top();
						s.pop();
					}
					s.push(c);
				}
			}
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << ' ' << maxSize << '\n';
	}
}