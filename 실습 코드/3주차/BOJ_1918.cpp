//
// Created by 이승준 on 3/17/25.
//
#include <iostream>
using namespace std;

class Node {
public:
    char value;
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
    void Append(char x) {
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

    char top(){
        if (isEmpty()){
            return -1;
        }
        return ll.head->next->value;
    }

    void push(char x){
        ll.Append(x);
    }

    void pop(){
        if (isEmpty()){
            return;
        }
        ll.Delete();
    }
};

// 입력값이 연산자임을 판별
bool isOper(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 입력값이 숫자(알파벳)임을 판별
bool isNum(char c)
{
    return (c >= 65 && c <= 90); // 아스키코드 이용 ('A' -> 65, 'Z' -> 90)
}

int main()
{
    Stack s;
    string j;
    cin >> j;
    for (size_t i{ 0 }; i < j.size(); i++)
    {
        char c = j[i];
        if (isNum(c))
        {
            cout << c;
        }
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (isOper(s.top())) {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOper(c))
        {
            if (c == '+' || c == '-')
            {
                while (true) {
                    if (s.isEmpty())
                        break;

                    if (isOper(s.top()))
                    {
                        cout << s.top();
                        s.pop();
                    }

                    else
                        break;
                }
                s.push(c);
            }
            else if (c == '*' || c == '/')
            {
                while (true) {
                    if (s.isEmpty())
                        break;
                    if (s.top() == '*' || s.top() == '/')
                    {
                        cout << s.top();
                        s.pop();
                    }
                    else
                        break;
                }
                s.push(c);
            }
        }

    }

    while (!s.isEmpty())
    {
        cout << s.top();
        s.pop();
    }

}