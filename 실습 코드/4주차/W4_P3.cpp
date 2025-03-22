#include <iostream>
using namespace std;

int maxSize;

class Queue {
public:
    int* arr = new int[maxSize];
    int size = 0;
    int f = 0;
    int r = -1;

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }

    bool full() {
        return size == maxSize;
    }

    int front() {
        return arr[f];
    }

    int rearNsum(int n) {
        if (empty() || n > getSize())
            return -1;

        int sum = 0;
        int idx = r;

        while (n--){
            sum += arr[idx];
            idx = (idx - 1) % maxSize;
        }

        return sum;
    }

    void enqueue(int x) {
        if (full()){
            cout << "Full\n";
            return;
        }
        r = (r+1) % maxSize;
        arr[r] = x;
        size++;
    }

    void dequeue() {
        if (empty()){
            cout << "Empty\n";
            return;
        }
        cout << front() << '\n';
        f = (f+1) % maxSize;
        size--;
    }
};

int main() {
    int t;
    cin >> maxSize >> t;

    Queue q = Queue();

    while (t--) {
        string str;
        cin >> str;

        if (str == "size")
            cout << q.getSize() << '\n';
        else if (str == "isEmpty") {
            if (q.empty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (str == "full") {
            if (q.full())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (str == "front") {
            if (q.empty())
                cout << "Empty\n";
            else
                cout << q.front() << '\n';
        }
        else if (str == "rearNsum") {
            int n;
            cin >> n;

            if (q.empty())
                cout << "Empty\n";
            else if (n > q.getSize())
                cout << "error\n";
            else
                cout << q.rearNsum(n) << '\n';
        }
        else if (str == "enqueue") {
            int x;
            cin >> x;

            q.enqueue(x);
        }
        else if (str == "dequeue") {
            q.dequeue();
        }
    }
}