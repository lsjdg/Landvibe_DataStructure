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

    bool compare(int a, int b) {
        if ((v[a] % 2 != v[b] % 2)) 
            return v[a] % 2 > v[b] % 2;
        if (v[a] % 2 == 1)
            return v[a] > v[b];
        return v[a] < v[b];
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
        int parentIdx = idx / 2;

        if (compare(idx, parentIdx)) {
            swap(parentIdx, idx);
            upHeap(parentIdx);
        }
    }

    void downHeap(int idx) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int maxIdx = idx;

        if (left <= size && compare(left, maxIdx))
            maxIdx = left;
        if (right <= size && compare(right, maxIdx))
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

    int pop() {
        int top = v[rootIdx];
        v[rootIdx] = v[size];
        v.pop_back();
        size--;
        downHeap(rootIdx);
        return top;
    }
};

int main() {
    int test;
    cin >> test;

    while (test--) {
        int books;
        cin >> books;

        Heap h = Heap();

        for (int i{ 0 }; i < books; i++) {
            int x;
            cin >> x;

            h.push(x);
        }

        while (!h.isEmpty())
            cout << h.pop() << ' ';
        cout << '\n';
    }
}