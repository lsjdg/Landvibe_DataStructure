# main 문 작성법
```cpp
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    linkedList ll;
    cin >> m;
    while (m--) { // m번 반복하겠다는 의미
        string cmd; // 명령어 변수
        int x, i; // 추가로 필요할 수 있는 변수
        cin >> cmd; // 명령어 입력
        if (cmd == "Print") { // 문제에 나와 있는 그대로 적으세요
            ll.print(); 
        } else if (cmd == "AddFront") {
            cin >> x;
            ll.addFront(x);
        } else if (cmd == "RemoveFront") {
            ll.removeFront();
        } else if (cmd == "Update") {
            cin >> i >> x;
            ll.update(i, x);
        } else if (cmd == "Min") {
            ll.min();
        }
    }
}
```
- `while (m--) ` : m번 반복
while 문 안에 있는 코드 실행

c++에서 
0  : false, 0이 아닌 정수 : true로 인식

m이 1씩 빠지면서 m번 반복하면 0이됨

- 이상한 세줄
```cpp
cin.tie(nullptr);
cout.tie(nullptr);
ios::sync_with_stdio(false);
```
이거 쓰면 입출력이 빨라집니다. 자세한건 나중에 알게됩니다 :)

- 입력 명령어 문제에 나와있는 그대로 적기

(_이걸로 실수 하는 경우가 있더라고요. 문제에서 그대로 복붙하세요_)

- 요구사항 구현

함수에서 요구사항에 있는대로 다 구현해도 되고

if문안에 요구사항에 맞춰 추가로 구현해도 됩니다.

ex.)
```cpp
void linkedList::removeFront() {
    if (empty()) {
        cout << "empty\n";
        return;
    }
    Node *delNode = head;
    int delVal = delNode->val;
    head = delNode->next;
    delete delNode;
    size--;
    cout << delVal << "\n";
}
```
or
```cpp
int linkedList::removeFront() {
    if (empty()) {
        cout << "empty\n";
        return -1;
    }
    Node *delNode = head;
    int delVal = delNode->val;
    head = delNode->next;
    delete delNode;
    size--;
    return delVal;
}
```
```cpp
//main
else if (cmd == "RemoveFront") {
     cout << ll.removeFront() << "\n";
} 

```
