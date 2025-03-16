#include <iostream>
using namespace std;

class Node {
public:
    int value; // 정수를 저장하는 노드
    Node* next; // 다음 노드의 주소를 가리키는 포인터

    Node() {
        this->value = 0; // 기본값을 0으로 설정
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head; // 맨 앞의 노드를 가리키는 포인터 변수
    Node* tail; // 맨 끝의 노드를 가리키는 포인터 변수
    int size; // 연결 리스트에 포함된 노드의 갯수

    // 생성자 함수
    SinglyLinkedList() {
        head = new Node(); // Dummy Node
        tail = new Node();
        head->next = tail; // head 와 tail 연결
        size = 0;
    }
    
    // : head에서 tail 방향으로 리스트를 순회하며 각 노드에 저장된 자연수를 출력
    void Print() {
        if (size == 0)
            cout << "empty" << '\n';
        else {
            Node* curNode = head->next; // Dummy Node 의 다음 노드부터 시작

            for (int i{ 0 }; i < size; i++) {
                cout << curNode->value << ' ';
                curNode = curNode->next; // 다음 노드로 이동
            }
            cout << '\n';
        }
    }

    // 노드를 리스트의 가장 뒤에 삽입하고 Print 함수를 수행
    void Append(int x) {
        // 연결 리스트의 크기는 런타임에 변할 수 있음 -> Node 객체를 동적으로 할당
        Node* newNode = new Node();
        newNode->value = x;
        Node* curNode = head;
        for (int i{ 0 }; i < size; i++) {
            curNode = curNode->next;
        }
        newNode->next = tail; // 새로 삽입된 노드의 다음 노드는 tail 이다
        curNode->next = newNode;
        size++;
        Print();
    }

    // index의 노드를 삭제하면서 노드에 저장된 자연수를 반환
    void Delete(int idx) {
        // 리스트가 비어있거나 인덱스가 잘못된 경우 예외처리
        if (size == 0 || idx >= size)
            cout << -1 << '\n';
        else {
            Node* curNode = head;

            // idx - 1 번 째 노드까지 이동
            for (int i{ 0 }; i < idx; i++) {
                curNode = curNode->next;
            }

            Node* delNode = curNode->next; // 삭제할 노드 정의
            curNode->next = delNode->next;
            cout << delNode->value << '\n';
            delete delNode;
            size--;
        }
    }

    // idx 부터 이후의 값 중에서 가장 큰 값을 출력하는 함수
    void AfterMax(int idx) {
        if (size == 0 || idx >= size)
            cout << "error" << '\n';
        else {
            Node* curNode = head->next;

            for (int i{ 0 }; i < idx; i++) {
                curNode = curNode->next;
            }

            int max = curNode->value;

            // 최댓값을 구하기 위해 순회
            while (curNode != this->tail) {
                if (max < curNode->value)
                    max = curNode->value;
                curNode = curNode->next;
            }

            cout << max << '\n';
        }
    }

    // 노드들에 저장된 자연수들의 합을 출력하는 함수
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
        else if (str == "AfterMax") {
            int idx;
            cin >> idx;

            l.AfterMax(idx);
        }
        else if (str == "Sum") {
            l.Sum();
        }
    }
}