#include <iostream>
using namespace std;

int t = 10001;

class Stack {
public:
    int* arr;
    int f;
    int size;

    Stack() {
        arr = new int[t];
        size = 0;
        f = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (this->size == 0);
    }

    bool full() {
        return (size == t);
    }

    int top() {
        if (isEmpty())
            return -1;
        else return arr[this->f];
    }

    void push(int x) {
        if (full())
            return;
        else {
            this->f++;
            arr[this->f] = x;
            size++;
        }
    }

    void pop() {
        if (isEmpty())
            return;
        else {
            this->f--;
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
        Stack s = Stack();
        string str;
        int k;
        cin >> str >> k;

        for (int i{ 0 }; i < str.size(); i++) {
            char c = str[i];

            if (!isOper(c)) {
                s.push(c - '0');
            }
            else {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                if (c == '+')
                    s.push(left + right);
                else if (c == '-')
                    s.push(left - right);
                else if (c == '*')
                    s.push(left * right);
            }
        }
        int result = (s.top() > 0 ? s.top() : s.top() * -1);
        
        cout << result % k << '\n';
    }
}
