//
// Created by 이승준 on 3/16/25.
//
#include <iostream>
using namespace std;

int t; // 배열의 크기를 전역으로 선언

class Stack {
public:
    int* arr; // 배열을 이용한 구현
    int front; // front 의 index
    int size; // 스택에 저장된 원소의 갯수

    Stack() {
        arr = new int[t];
        size = 0;
        front = 0;
    }

    // 스택의 크기 반환
    int getSize() {
        return this->size;
    }

    // 스택이 비어있는지 검사
    bool isEmpty() {
        return (this->size == 0);
    }

    // 스택이 꽉 찼는지 검사
    bool full() {
        return (this->size == t);
    }

    // 스택의 top 에 있는 원소를 반환
    int top() {
        if (isEmpty()) // 스택이 비어있는 경우 예외처리
            return -1;
        return arr[this->front];
    }

    // 스택에 원소를 삽입
    void push(int x) {
        if (full()) { // 스택이 꽉 찬 경우 예외처리
            cout << "FULL\n";
            return;
        }
        this->front++;
        arr[this->front] = x;
        size++;
    }

    // 스택의 맨 위 원소를 삭제
    void pop() {
        if (isEmpty()) // 스택이 비어있는 경우 예외처리
            return;
        this->front--;
        size--;
    }

    // 스택의 위쪽에 있는 s 개의 원소를 합하고 pop
    void popsum(int s) {
        if (isEmpty()){
            cout << "-1\n";
        }
        else if (s > size) {
            int sum{ 0 };
            while (!isEmpty()) {
                sum += top();
                pop();
            }
            cout << sum << '\n';
        }
        else {
            int sum{ 0 };
            for (int i{ 0 }; i < s; i++) {
                sum += top();
                pop();
            }
            cout << sum << '\n';
        }
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
        }
        else if (str == "top") {
            if (st.isEmpty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
        else if (str == "push") {
            int x;
            cin >> x;

            if (st.full())
                cout << "FULL\n";
            else
                st.push(x);
        }
        else if (str == "popsum") {
            int s;
            cin >> s;

            if (st.isEmpty())
                cout << -1 << '\n';
            else
                st.popsum(s);
        }
    }
}
