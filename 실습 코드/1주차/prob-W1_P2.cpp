//
// Created by 이승준 on 3/5/25.
//
#include <iostream>
using namespace std;

class Array {
public:
    int* arr;
    int size;

    Array(int size) {
        this->size = size;
        arr = new int[size];

        for (int i{0}; i < size; i++){
            arr[i] = i;
        }
    }

    void shift(int i, int j){
        int temp = arr[j];

        for (int k{ j - 1 }; k >= i; k--)
            arr[k + 1] = arr[k];

        arr[i] = temp;
    }

    void swap(int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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

        if (str == "shift") {
            int i, j;
            cin >> i >> j;

            arr.shift(i, j);
        }
        else if (str == "swap") {
            int i, j;
            cin >> i >> j;

            arr.swap(i, j);
        }
        else if (str == "print") {
            arr.print();
        }
    }
}