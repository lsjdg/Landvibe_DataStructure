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

    void push(int e) {
        v.push_back(e);
    }

    int pop() {
        if (!isEmpty()) {
            vector<int>::iterator i;
            int maxVal = v[0];

            for (i = v.begin(); i != v.end(); i++) {
                if (maxVal < *i)
                    maxVal = *i;
            }

            for (i = v.begin(); i != v.end(); i++) {
                if (maxVal == *i) {
                    v.erase(i);
                    break;
                }
            }

            return maxVal;
        }
    }
};

int main() {
    int test, elem, step;
    cin >> test;

    while (test--) {
        PQueue pq;
        vector<int> seq;
        cin >> elem;

        for (int i{ 0 }; i < elem; i++) {
            int x;
            cin >> x;

            seq.push_back(x);
        }

        cin >> step;

        int i{ 0 };
        for (; i < min(step, (int)seq.size()); i++) 
            pq.push(seq[i]);
        
        seq.erase(seq.begin(), seq.begin() + i);

        if (step > elem) {
            int removeCount = step - elem;

            for (int j{ 0 }; j < removeCount; j++) {
                if (!pq.isEmpty()) {
                    int val = pq.pop();
                    seq.push_back(val);
                }
            }
        }

        cout << "S : ";
        for (int i{ 0 }; i < seq.size(); i++)
            cout << seq[i] << ' ';
        cout << '\n';

        cout << "PQ : ";
        for (int i{ 0 }; i < pq.size(); i++)
            cout << pq.v[i] << ' ';
        cout << '\n';
    }
}