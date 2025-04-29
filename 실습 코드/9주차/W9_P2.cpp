#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
    vector<int> v;

    int size() {
        return v.size();
    }

    bool isEmpty() {
        return v.size() == 0;
    }

    int numCount(int e) {
        int count = 0;
        while (e > 0) {
            count++;
            e /= 10;
        }
        return count;
    }

    void push(int e) {
        v.push_back(e);
    }

    int pop() {
        if (isEmpty()) 
            return -1; 

        auto it = v.begin();
        for (auto i = v.begin() + 1; i != v.end(); ++i) {
            int itNumCount = numCount(*it);
            int iNumCount = numCount(*i);

            if (iNumCount < itNumCount || (iNumCount == itNumCount && *i > *it)) {
                it = i;
            }
        }

        int max = *it;
        v.erase(it);
        return max;
    }
};

int main() {
    int test, elem, x;
    cin >> test;

    for (int i{ 1 }; i <= test; i++) {
        PQueue pq;
        cin >> elem;

        cout  << "Case #" << i << ".\n";

        for (int i = 0; i < elem; ++i) {
            cin >> x;
            pq.push(x);
        }

        for (int i = 0; i < elem; ++i) {
            cout << pq.pop() << ' ';
        }
        cout << '\n';
    }
}
