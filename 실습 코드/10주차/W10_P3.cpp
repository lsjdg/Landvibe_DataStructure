#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    vector<int> v;
    int size = 0;
    int rootIdx = 1;

    Heap() {
        v.push_back(-1);
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void swap(int a, int b) {
        v[0] = v[a];
        v[a] = v[b];
        v[b] = v[0];
    }

    void upHeap(int idx) {
        if (idx == rootIdx)
            return;
        
        int parentIdx = idx / 2;

        if (v[parentIdx] < v[idx]) {
            swap(parentIdx, idx);
            upHeap(parentIdx);
        }
    }

    void downHeap(int idx) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int maxIdx = idx;

        if (left <= size && v[left] > v[maxIdx])
            maxIdx = left;
        if (right <= size && v[right] > v[maxIdx])
            maxIdx = right;
        if (maxIdx != idx) {
            swap(maxIdx, idx);
            downHeap(maxIdx);
        }
    }

    void push(int num) {
        v.push_back(num);
        size++;
        upHeap(size);
    }

    void pop() {
        if (isEmpty()) {
            cout << -1 << '\n';
            return;
        }
        cout << v[rootIdx] << '\n';
        v[rootIdx] = v[size];
        size--;
        v.pop_back();
        downHeap(rootIdx);
    }

    void top() {
        if (isEmpty()) {
            cout << -1 << '\n';
            return;
        }
        cout << v[rootIdx] << '\n';
    }

    void second_top() {
        if (size < 2) {
            cout << "Error\n";
            return;
        }
        else if (size == 2) {
            cout << v[rootIdx + 1] << '\n';
            return;
        }
        else {
            int left = rootIdx * 2;
            int right = rootIdx * 2 + 1;

            cout << (v[left] > v[right] ? v[left] : v[right]) << '\n';
        }
    }
};

int main() {
    int test;
    cin >> test;

    Heap h = Heap();

    while (test--) {
        string str; 
        cin >> str;

        if (str == "push") {
            int i;
            cin >> i;

            h.push(i);
        }
        else if (str == "size")
            cout << h.getSize() << '\n';
        else if (str == "empty")
            cout << h.isEmpty() << '\n';
        else if (str == "pop")
            h.pop();
        else if (str == "top")
            h.top();
        else if (str == "second_top")
            h.second_top();
    }
}