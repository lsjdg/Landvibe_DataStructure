//
// Created by 이승준 on 3/10/25.
//
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node* prev;
    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = 0;
    }
};
class DoubleLinkedList
{
public:
    Node* head;
    Node* tail;
    int size;
    DoubleLinkedList()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void print()
    {
        if (size == 0)
            cout << "empty" << '\n';
        else
        {
            Node* curNode = head->next;
            for (int i{ 0 }; i < size; i++)
            {
                cout << curNode->value << ' ';
                curNode = curNode->next;
            }
            cout << '\n';
        }
    }
    void insert(int idx, int x)
    {
        if (idx > size)
        {
            cout << "error" << '\n';
        }
        else
        {
            Node* newNode = new Node();
            newNode->value = x;
            Node* curNode = head;
            for (int i{ 0 }; i < idx; i++)
            {
                curNode = curNode->next;
            }
            newNode->next = curNode->next;
            curNode->next->prev = newNode;
            newNode->prev = curNode;
            curNode->next = newNode;
            size++;
        }
    }
    void remove(int idx)
    {
        if (size == 0 || idx >= size)
            cout << "error" << '\n';
        else
        {
            Node* delNode = head->next;
            for (int i{ 0 }; i < idx; i++)
            {
                delNode = delNode->next;
            }
            delNode->prev->next = delNode->next;
            delNode->next->prev = delNode->prev;
            cout << delNode->value << '\n';
            delete delNode;
            size--;
        }
    }
    void removeAll(int x)
    {
        int count{ 0 };
        Node* curNode = this->head->next;
        while (curNode != tail)
        {
            if (curNode->value == x)
            {
                curNode->prev->next = curNode->next;
                curNode->next->prev = curNode->prev;
                count++;
                size--;
            }
            curNode = curNode->next;
        }

        if (count == 0)
            cout << "not found" << '\n';
        else
            cout << count << '\n';
    }
    void neighborMax(int idx)
    {
        if (idx >= size)
        {
            cout << "error" << '\n';
        }
        else
        {
            Node* curNode = head->next;
            for (int i{ 0 }; i < idx; i++)
            {
                curNode = curNode->next;
            }
            int left = curNode->prev->value;
            int right = curNode->next->value;
            cout << (left <= right ? right : left) << '\n';
        }
    }
};

int main()
{
    DoubleLinkedList l = DoubleLinkedList();
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        if (s == "Print")
        {
            l.print();
        }
        else if (s == "Insert")
        {
            int idx, x;
            cin >> idx >> x;
            l.insert(idx, x);
        }
        else if (s == "Remove")
        {
            int idx;
            cin >> idx;
            l.remove(idx);
        }
        else if (s == "RemoveAll")
        {
            int x;
            cin >> x;
            l.removeAll(x);
        }
        else if (s == "NeighborMax")
        {
            int idx;
            cin >> idx;
            l.neighborMax(idx);
        }
    }
}