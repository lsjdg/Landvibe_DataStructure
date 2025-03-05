//
// Created by 이승준 on 3/5/25.
//
#include <iostream>
using namespace std;

class Array {
public:
    int* arr; // 배열의 시작 주소를 나타낼 포인터 변수
    int size; // 배열의 크기를 지정

    // 생성자 함수
    Array(int size) {
        this->size = size;
        // 동적 배열 생성, 첫 원소의 주소가 arr 에 저장
        // 모든 원소를 0으로 초기화
        arr = new int[size] { 0, };
    }

    // 특정 인덱스에 접근해 해당하는 원소를 반환
    void at(int idx) {
        cout << arr[idx] << '\n';
    }

    void add(int idx, int value) {
        // 인덱스 N-2 부터 idx 까지의 원소를 오른쪽으로 한 칸씩 옮김
        for (int i{ size - 2 }; i >= idx; i--) // 오른쪽 원소부터 처리
            arr[i + 1] = arr[i]; // i 번째 원소를 인덱스 i+1 로 이동(오른쪽으로 옮김)
        arr[idx] = value; // 인덱스 idx 에 value 삽입
    }

    void remove(int idx) {
        // 인덱스 idx+1 부터 N-1 까지의 원소를 왼쪽으로 한 칸씩 옮김
        for (int i{ idx + 1 }; i <= size - 1; i++)
            arr[i - 1] = arr[i];
        arr[size - 1] = 0;
    }

    // 특정 인덱스에 접근해 원소를 교체
    void set(int idx, int value) {
        arr[idx] = value;
    }

    void count(int value) {
        int count{ 0 };
        // 배열을 순회하며 value 의 갯수 출력
        for (int i{ 0 }; i < size; i++) {
            if (arr[i] == value)
                count++;
        }

        cout << count << '\n';
    }

    void print() {
        for (int i{ 0 }; i < size; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
};

int main() {
    int test, arrSize;
    cin >> test >> arrSize;

    Array arr = Array(arrSize);

    while (test--) {
        string str;
        cin >> str;

        if (str == "at") {
            int i;
            cin >> i;

            arr.at(i);
        }
        else if (str == "add") {
            int i, z;
            cin >> i >> z;

            arr.add(i, z);
        }
        else if (str == "remove") {
            int i;
            cin >> i;

            arr.remove(i);
        }
        else if (str == "set") {
            int i, z;
            cin >> i >> z;

            arr.set(i, z);
        }
        else if (str == "count") {
            int z;
            cin >> z;

            arr.count(z);
        }
        else if (str == "print") {
            arr.print();
        }
    }
}