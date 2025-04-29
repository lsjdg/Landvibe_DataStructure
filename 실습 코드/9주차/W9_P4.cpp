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
        int count{ 0 };

        while (e > 0) {
            count++;
            e /= 10;
        }

        return count;
    }

    void push(int e) {
        vector<int>::iterator it;
        int eNumCount = numCount(e);

        for (it = v.begin(); it != v.end(); it++) {
            int itNumCount = numCount(*it);

            if (itNumCount < eNumCount || (itNumCount == eNumCount && *it > e)) {
                break;
            }
        }
        v.insert(it, e);
    }

    int pop() {
        if (!isEmpty()) {
            int minVal = v.front();
            v.erase(v.begin());
            return minVal;
        }
        return -1;
    }
};

int main() {
    int test, elem;
    cin >> test;

    for (int i{ 1 }; i <= test; i++) {
        PQueue pq;
        cin >> elem;

        cout << "Case #" << i << ".\n";
        
        for (int j{ 0 }; j < elem; j++) {
            int x;
            cin >> x;

            pq.push(x);
        }

        for (int j{ 0 }; j < elem; j++)
            cout << pq.pop() << ' ';
        cout << '\n';
    }
}
